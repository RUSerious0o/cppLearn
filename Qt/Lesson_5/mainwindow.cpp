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

#include <utility>

#include "helpDialog.h"
#include "shortcutsprefsdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , help(new HelpDialog(this))
    , shortcutsDialog(new ShortcutsPrefsDialog(this))
    , shortcutsEventFilter(new ShortcutsEventFilter)
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
    }

    return QObject::eventFilter(obj, event);
}


