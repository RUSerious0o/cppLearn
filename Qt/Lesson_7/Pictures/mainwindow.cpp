#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mygpaphicsview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setCentralWidget(new MyGraphicsView(this));
    resize(800,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

