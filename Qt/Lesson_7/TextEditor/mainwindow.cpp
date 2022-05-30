#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fileexplorer.h"

#include <QFileDialog>
#include <QString>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QAction>
#include <QMenu>
#include <QEvent>
#include <QKeyEvent>
#include <QFileSystemModel>
#include <QTreeView>

#include <QFontDialog>
#include <QFont>
#include <QTextCharFormat>

#include <utility>

#include "helpDialog.h"
#include "shortcutsprefsdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , help(new HelpDialog(this))
    , shortcutsDialog(new ShortcutsPrefsDialog(this))
    , shortcutsEventFilter(new ShortcutsEventFilter)
    , currentTheme(Dark)
    , storedCharFormat(false, {})
{
    ui->setupUi(this);
    resize(1024,768);

    connect(ui->saveFileAction, &QAction::triggered, this, &MainWindow::onSaveFileActionTriggered);
    connect(ui->openFileAction, &QAction::triggered, this, &MainWindow::onOpenFileActionTriggered);
    connect(ui->showHelpAction, &QAction::triggered, this, &MainWindow::onShowHelpTriggered);
    connect(ui->readOnlyAction, &QAction::triggered, this, &MainWindow::onReadOnlyOpenFileActionTriggered);
    connect(ui->newFileAction, &QAction::triggered, this, &MainWindow::onNewFileTriggered);
    connect(ui->shortcutsPrefsAction, &QAction::triggered, this, &MainWindow::onShortcutsDialogShowAction);
    connect(ui->translationChangeAction, &QAction::triggered, this, &MainWindow::onTranslationChangeTriggered);

    if(!QDir().exists(FILES_DEFAULT_DIR)) {
        QDir().mkdir(FILES_DEFAULT_DIR);
    }

    installEventFilter(shortcutsEventFilter);

    currentTranslation = RUSSIAN_TR;
    setTranslation(currentTranslation);
    setupHelp();

    fileExplorer = new FileExplorer(this);
    ui->hLayout->insertWidget(0, fileExplorer, 2);
    connect(fileExplorer, &FileExplorer::itemSelected, this, &MainWindow::onFileExplorerItemSelected);

    connect(ui->changeThemeAction, &QAction::triggered, this, &MainWindow::onChangeThemeTriggered);
    setTheme(currentTheme);

    setupToolBar();
}

MainWindow::~MainWindow()
{    
    delete shortcutsEventFilter;    
    delete ui;
}

void MainWindow::setupHelp()
{
    if(currentTranslation == RUSSIAN_TR) {
        help->setContent(RUSSIAN_HELP);
    } else {
        help->setContent(ENGLISH_HELP);
    }
}

void MainWindow::onSaveFileActionTriggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, SAVE_DIALOG_CAPTION, FILES_DEFAULT_DIR, OPEN_SAVE_DIALOG_FILTER);
    QFile file(fileName);
    if(file.open(QFile::WriteOnly)) {
        QTextStream text(&file);
        text << ui->textEdit->toPlainText();
        file.close();
    }
}

void MainWindow::onOpenFileActionTriggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, OPEN_DIALOG_CAPTION, FILES_DEFAULT_DIR, OPEN_SAVE_DIALOG_FILTER);
    QFile file(fileName);
    if(file.open(QFile::ReadOnly | QFile::ExistingOnly)) {
        QTextStream text(&file);
        ui->textEdit->setPlainText(text.readAll());
        file.close();
    }
    setMode(Normal);
}

void MainWindow::onReadOnlyOpenFileActionTriggered()
{
    onOpenFileActionTriggered();
    setMode(ReadOnly);
}

void MainWindow::onShowHelpTriggered()
{
    help->show();
}

void MainWindow::onNewFileTriggered()
{
    ui->textEdit->clear();
    setMode(Normal);
}

void MainWindow::onShortcutsDialogShowAction()
{
    shortcutsDialog->show();
}

void MainWindow::onTranslationChangeTriggered()
{
    if(currentTranslation == ENGLISH_TR) {
        currentTranslation = RUSSIAN_TR;
    } else if (currentTranslation == RUSSIAN_TR) {
        currentTranslation = ENGLISH_TR;
    }

    setTranslation(currentTranslation);
    setupHelp();
}

void MainWindow::onFileExplorerItemSelected(const QString &filePath)
{
    if(filePath.contains(".txt")) {
        setMode(ReadOnly);
        QFile file(filePath);
        if(file.open(QFile::ReadOnly | QFile::ExistingOnly)) {
            QTextStream text(&file);
            ui->textEdit->setPlainText(text.readAll());
            file.close();
        }
    }
}

void MainWindow::onChangeThemeTriggered()
{
    if(currentTheme == Dark) {
        currentTheme = Light;
    } else {
        currentTheme = Dark;
    }
    setTheme(currentTheme);
}

void MainWindow::onChangeFontActionTriggered()
{
    QFont font = ui->textEdit->textCursor().charFormat().font();
    bool fontSelected[] = { true };

    QFontDialog fontDialog(font, this);
    font = fontDialog.getFont(fontSelected);
    if(fontSelected[0]) {
        QTextCharFormat format;
        format.setFont(font);
        ui->textEdit->textCursor().setCharFormat(format);
    }
}

void MainWindow::onCopyFormatActionTriggered()
{
    storedCharFormat = { true,  ui->textEdit->textCursor().charFormat() };
}

void MainWindow::onPasteFormatActionTriggered()
{
    if(!storedCharFormat.first) return;
    ui->textEdit->textCursor().setCharFormat(storedCharFormat.second);
}

void MainWindow::onTextAlignLeftActionTriggered()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}

void MainWindow::onTextAlignRightActionTriggered()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}

void MainWindow::onTextAlignCenterActionTriggered()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}



void MainWindow::setMode(EditMode mode)
{
    if(mode == ReadOnly) {
        ui->textEdit->setReadOnly(true);
        ui->saveFileAction->setEnabled(false);
    } else if (mode == Normal) {
        ui->textEdit->setReadOnly(false);
        ui->saveFileAction->setEnabled(true);
    }
}

void MainWindow::setTranslation(QString translation)
{
    translator.load(translation);
    qApp->installTranslator(&translator);
    ui->retranslateUi(this);
}

void MainWindow::setupToolBar()
{
    QAction *action = new QAction (QIcon(FONT_ICON_PATH), FONT_ICON_TOOLTIP, this);
    connect(action, &QAction::triggered, this, &MainWindow::onChangeFontActionTriggered);
    ui->toolBar->addAction(action);

    action = new QAction(QIcon(SAVE_FORMAT_ICON_PATH), SAVE_FORMAT_ICON_TOOLTIP, this);
    connect(action, &QAction::triggered, this, &MainWindow::onCopyFormatActionTriggered);
    ui->toolBar->addAction(action);

    action = new QAction(QIcon(PASTE_FORMAT_ICON_PATH), PASTE_FORMAT_ICON_TOOLTIP, this);
    connect(action, &QAction::triggered, this, &MainWindow::onPasteFormatActionTriggered);
    ui->toolBar->addAction(action);

    action = new QAction(QIcon(TEXT_ALIGN_LEFT_ICON_PATH), TEXT_ALIGN_LEFT_TOOLTIP, this);
    connect(action, &QAction::triggered, this, &MainWindow::onTextAlignLeftActionTriggered);
    ui->toolBar->addAction(action);

    action = new QAction(QIcon(TEXT_ALIGN_CENTER_ICON_PATH), TEXT_ALIGN_CENTER_TOOLTIP, this);
    connect(action, &QAction::triggered, this, &MainWindow::onTextAlignCenterActionTriggered);
    ui->toolBar->addAction(action);

    action = new QAction(QIcon(TEXT_ALIGN_RIGHT_ICON_PATH), TEXT_ALIGN_RIGHT_TOOLTIP, this);
    connect(action, &QAction::triggered, this, &MainWindow::onTextAlignRightActionTriggered);
    ui->toolBar->addAction(action);
}

void MainWindow::setTheme(Theme theme)
{
    QFile file(themes[theme]);
    if(file.open(QFile::ReadOnly | QFile::ExistingOnly)) {
        QTextStream text(&file);
        qApp->setStyleSheet(text.readAll());
        file.close();
    }
}


MainWindow::ShortcutsEventFilter::ShortcutsEventFilter(QObject *parent) : QObject(parent) {}

bool MainWindow::ShortcutsEventFilter::eventFilter(QObject *obj, QEvent *event) {
    if(event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        MainWindow *mainWindow = static_cast<MainWindow*>(obj);

        std::pair<int, Qt::KeyboardModifiers> saveFileSrortcut = mainWindow->shortcutsDialog->getSaveFileActionShortcut();
        if(keyEvent->key() == saveFileSrortcut.first && keyEvent->modifiers() == saveFileSrortcut.second) {
            if(mainWindow->ui->saveFileAction->isEnabled()) {
                mainWindow->onSaveFileActionTriggered();
            }
            return true;
        }

        std::pair<int, Qt::KeyboardModifiers> openFileSrortcut = mainWindow->shortcutsDialog->getOpenFileActionShortcut();
        if(keyEvent->key() == openFileSrortcut.first && keyEvent->modifiers() == openFileSrortcut.second) {
            mainWindow->onOpenFileActionTriggered();
            return true;
        }

        if(keyEvent->key() == Qt::Key_N && keyEvent->modifiers() == Qt::ControlModifier) {
            mainWindow->onNewFileTriggered();
            return true;
        }

        if(keyEvent->key() == Qt::Key_Q && keyEvent->modifiers() == Qt::ControlModifier) {
            mainWindow->close();
            return true;
        }

        if(keyEvent->key() == Qt::Key_L && keyEvent->modifiers() == Qt::ControlModifier) {
            mainWindow->onTranslationChangeTriggered();
            return true;
        }

        if(keyEvent->key() == Qt::Key_T && keyEvent->modifiers() == Qt::ControlModifier) {
            mainWindow->onChangeThemeTriggered();
            return true;
        }
    }

    return QObject::eventFilter(obj, event);
}


