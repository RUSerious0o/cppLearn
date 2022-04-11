#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QString>
#include <QDir>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(800,600);

    connect(ui->saveFileAction, &QAction::triggered, this, &MainWindow::onSaveFileActionTriggered);
    connect(ui->openFileAction, &QAction::triggered, this, &MainWindow::onOpenFileActionTriggered);

    if(!QDir().exists(FILES_DEFAULT_DIR)) {
        QDir().mkdir(FILES_DEFAULT_DIR);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    ui->verticalLayoutWidget->setFixedSize(this->size());
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
}

