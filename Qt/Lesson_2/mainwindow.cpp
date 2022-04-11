#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextEdit>
#include <QLabel>
#include <QStandardItemModel>
#include <QListView>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupList();
    setupTable();

    ui->textEdit->setText("#@RUB@ - рубли\n#@PROM@ - промилле");
}

MainWindow::~MainWindow()
{
    delete listModel;
    delete tableHeaderModel;
    delete tableModel;
    delete ui;
}


void MainWindow::on_textEdit_textChanged()
{
    QString text = ui->textEdit->toPlainText();
    if(text.contains("#@")) {
        text.replace("#@RUB@", "₽");
        text.replace("#@PROM@", "‰");
    }
    ui->textEdit_2->setText(text);
}


void MainWindow::on_pushButton_released()
{
    if(ui->lineEdit->text() == "") return;

    listModel->appendRow(new QStandardItem(QIcon(":/icons/other.png"), ui->lineEdit->text()));
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(ui->checkBox->isChecked()) ui->listView->setViewMode(QListView::IconMode);
    else ui->listView->setViewMode(QListView::ListMode);
}


void MainWindow::on_pushButton_2_released()
{
    listModel->removeRow(ui->listView->currentIndex().row());
}


void MainWindow::on_pushButton_3_released()
{
    for(auto index : ui->tableView->selectionModel()->selectedIndexes()) {
        int rowId = index.row();

        auto row = tableModel->takeRow(rowId);
        for(QStandardItem* item : row) {
            item->setBackground(Qt::yellow);
        }
        tableModel->insertRow(rowId, row);
    }
}

void MainWindow::setupList()
{
    listModel = new QStandardItemModel(this);
    ui->listView->setModel(listModel);
    listModel->appendRow(new QStandardItem(QIcon(":/icons/C.png"), "C"));
    listModel->appendRow(new QStandardItem(QIcon(":/icons/Cpp.png"), "C++"));
    listModel->appendRow(new QStandardItem(QIcon(":/icons/Java.png"), "Java"));
    listModel->appendRow(new QStandardItem(QIcon(":/icons/Js.png"), "Java Script"));
    listModel->appendRow(new QStandardItem(QIcon(":/icons/Php.png"), "PHP"));
}

void MainWindow::setupTable()
{
    tableModel = new QStandardItemModel(this);
    ui->tableView->setModel(tableModel);

    tableHeaderModel = new QStandardItemModel(this);
    tableHeaderModel->setColumnCount(3);
    tableHeaderModel->setHeaderData(0, Qt::Horizontal, "Имя компьютера", Qt::DisplayRole);
    tableHeaderModel->setHeaderData(1, Qt::Horizontal, "IP", Qt::DisplayRole);
    tableHeaderModel->setHeaderData(2, Qt::Horizontal, "MAC", Qt::DisplayRole);
    ui->tableView->horizontalHeader()->setModel(tableHeaderModel);

    tableModel->appendRow(QList<QStandardItem*>{
        new QStandardItem("ПК Васи"),
        new QStandardItem("192.168.0.1"),
        new QStandardItem("8A:7C:B2:4B:BF:EC")
    });

    tableModel->appendRow(QList<QStandardItem*>{
        new QStandardItem("ПК Юры"),
        new QStandardItem("192.168.0.2"),
        new QStandardItem("8A:D1:41:82:05:FD")
    });

    tableModel->appendRow(QList<QStandardItem*>{
        new QStandardItem("ПК Иры"),
        new QStandardItem("192.168.0.3"),
        new QStandardItem("8A:60:50:92:D8:D9")
    });
}

