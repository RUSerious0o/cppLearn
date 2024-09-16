#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QQuickWidget>
#include <QQuickItem>
#include <QWidget>
#include <QLayout>
#include <QDebug>
#include <QSlider>
#include <QTableView>
#include <QList>
#include <QString>
#include <QFile>
#include <QStandardItemModel>
#include <QTextStream>
#include <QErrorMessage>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , inputInterfaceRoot(nullptr)
    , model(nullptr)
    , tasksTable(nullptr)
{
    ui->setupUi(this);
    setupInputInterface();
    setupTaskList();    
}

MainWindow::~MainWindow()
{
    saveValues();
    delete ui;
    delete inputInterfaceRoot;
    delete model;
    delete tasksTable;    
}

void MainWindow::setTaskName(const QString &taskName)
{
    inputInterfaceRoot->findChild<QObject*>(TASK_NAME_INPUT_WIDGET)->setProperty("text", taskName);
}

void MainWindow::setTaskDeadline(const QDate &date)
{
    inputInterfaceRoot->findChild<QObject*>(TASK_DEADLINE_INPUT_WIDGET)->setProperty("text", date.toString("dd.MM.yyyy"));
}

void MainWindow::setTaskProgress(int progress)
{
    inputInterfaceRoot->findChild<QObject*>(TASK_PROGRESS_WIDGET)->setProperty("value", progress % 10);
    inputInterfaceRoot->findChild<QObject*>(TASK_PROGRESS_WIDGET_TEXT)->setProperty("text", progress % 10);
}

int MainWindow::getTasksCount()
{
    return model->rowCount();
}

QList<QStandardItem *> MainWindow::takeTask(int taskId)
{
    return model->takeRow(taskId);
}

void MainWindow::onAddTaskRequested()
{
    if(!inputInterfaceRoot) {
        return;
    }

    std::vector<std::pair<QString, QObject*>> info {
        { TASK_NAME_INPUT_WIDGET, nullptr },
        { TASK_DEADLINE_INPUT_WIDGET, nullptr },
        { TASK_PROGRESS_WIDGET_TEXT, nullptr }
    };    
    QList<QStandardItem*> values;

    for(auto item : info) {
        item.second = inputInterfaceRoot->findChild<QObject*>(item.first);
        QString value = item.second->property("text").toString();
        if(value != "") {
            values.append(new QStandardItem(value));
        } else {
            (new QErrorMessage(this))->showMessage(ERROR_MESSAGE);
            return;
        }
    }

    model->appendRow(values);

    saveValues();
}

void MainWindow::setupInputInterface()
{
    QQuickWidget *inputInterface = new QQuickWidget(QUrl("qrc:/InputInterface.qml"), this);
    inputInterface->setFixedHeight(300);
    ui->gridLayout->addWidget(inputInterface, 0, 0);
    inputInterface->raise();

    inputInterfaceRoot = inputInterface->rootObject();
    if (inputInterfaceRoot) {
        auto addTaskButton = inputInterfaceRoot->findChild<QObject*>("addTaskButton");
        if(addTaskButton) {
            connect(addTaskButton, SIGNAL(addTaskRequest()), this, SLOT(onAddTaskRequested()));
        }

        setTaskName("Новая задача");
        setTaskDeadline(QDate::currentDate());
        setTaskProgress(3);
    }
}

void MainWindow::setupTaskList()
{
    model = new QStandardItemModel(this);
    model->setColumnCount(3);
    model->setHorizontalHeaderLabels({
                                         "Задача", "Срок", "Прогресс (n/10)"
                                     });

    tasksTable = new QTableView(this);
    ui->gridLayout->addWidget(tasksTable, 1, 0);
    tasksTable->setModel(model);
    tasksTable->setColumnWidth(0, 450);

    loadValues();    
}

void MainWindow::saveValues()
{
    if(model->rowCount() == 0) return;

    QFile saveFile(SAVE_FILE_NAME);
    if(saveFile.open(QIODevice::WriteOnly)) {
        QTextStream text(&saveFile);
        for(int i = 0; i < model->rowCount(); ++i) {
            auto row = model->takeRow(i);            
            QString s = QString("%1%2%3%4%5\n")
                    .arg(row.at(0)->text())
                    .arg(DELIMITER)
                    .arg(row.at(1)->text())
                    .arg(DELIMITER)
                    .arg(row.at(2)->text());
            text << s;
            model->insertRow(i, row);
        }
        saveFile.close();
    }
}

void MainWindow::loadValues()
{
    QFile saveFile(SAVE_FILE_NAME);
    if(!saveFile.open(QIODevice::ReadOnly)) return;

    QTextStream text(&saveFile);
    while(!text.atEnd()) {
        QString data = text.readLine();
        auto values = data.split(DELIMITER);
        //qDebug() << values;

        model->appendRow({
                             new QStandardItem(values[0]),
                             new QStandardItem(values[1]),
                             new QStandardItem(values[2])
                         });
    }


    saveFile.close();
}

