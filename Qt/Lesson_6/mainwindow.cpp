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
#include <QPrintDialog>
#include <QPrinter>
#include <QPainter>
#include <QMdiSubWindow>

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
    connect(ui->printAction, &QAction::triggered, this, &MainWindow::onPrintTriggered);

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

    ui->mdiArea->addSubWindow(ui->textEdit);
    ui->hLayout->setStretch(1, 5);
    ui->mdiArea->addSubWindow(new QTextEdit(this));
    ui->mdiArea->setActiveSubWindow(ui->mdiArea->subWindowList().at(0));
    ui->mdiArea->subWindowList().at(0)->resize(400, 700);
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
            //ui->textEdit->setPlainText(text.readAll());
            ((QTextEdit*)ui->mdiArea->activeSubWindow()->widget())->setPlainText(text.readAll());
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

void MainWindow::onPrintTriggered()
{
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    if(dialog.exec() != QDialog::Accepted) {
        return;
    }

    QString printStr = ui->textEdit->toPlainText();
    //QString printStr = ((QTextEdit*)ui->mdiArea->activeSubWindow()->widget())->toPlainText();     // throws error, not figured why...
    QChar *list = printStr.data();
    QStringList strlst;
    int line = 0, cursor = 0;
    for (bool getst = true;getst;)
    {
        int index = printStr.indexOf("\n", cursor);
        QString s = "";
        if (index == -1)
        {
            getst = false;
            s.append(&list[cursor], printStr.length() - cursor);
        }
        else {
            s.append(&list[cursor], index - cursor);
        }
        cursor = index + 1;
        strlst << s;
    }

    QPainter painter;
    painter.begin(&printer);
    int h = painter.window().height();
    int amount = strlst.count();
    QFontMetrics fmetrics(painter.font());
    for (int i = 0; i < amount; i++)
    {
        QPointF pf;
        pf.setX(10);
        line += fmetrics.height();
        pf.setY(line);
        painter.drawText(pf, strlst.at(i));
        if (h - line <= fmetrics.height())
        {
            printer.newPage();
            line = 0;
        }
    }
    painter.end();
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

        if(keyEvent->key() == Qt::Key_P && keyEvent->modifiers() == Qt::ControlModifier) {
            mainWindow->onPrintTriggered();
            return true;
        }
    }

    return QObject::eventFilter(obj, event);
}


