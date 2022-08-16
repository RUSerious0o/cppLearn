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
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , inputInterfaceRoot(nullptr)
    , tasksTable(nullptr)
    , dbModel(nullptr)
{
    ui->setupUi(this);
    setupDB();
    setupInputInterface();
    setupTaskList();    
}

MainWindow::~MainWindow()
{    
    delete ui;
    delete inputInterfaceRoot;
    delete tasksTable;
    delete dbModel;
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

    QSqlQuery(dbModel->database()).exec(getInsertTaskQuery(values));
    dbModel->select();
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
    dbModel = new QSqlTableModel(this);
    tasksTable = new QTableView(this);

    ui->gridLayout->addWidget(tasksTable, 1, 0);
    tasksTable->setModel(dbModel);

    dbModel->database().setDatabaseName(DB_NAME);
    dbModel->setTable(TABLE_NAME);

    dbModel->setHeaderData(0, Qt::Horizontal, "№");
    dbModel->setHeaderData(1, Qt::Horizontal, "Задача");
    dbModel->setHeaderData(2, Qt::Horizontal, "Срок");
    dbModel->setHeaderData(3, Qt::Horizontal, "Прогресс (1-10)");

    tasksTable->setColumnWidth(0, 12);
    tasksTable->setColumnWidth(1, 450);

    dbModel->select();
}

void MainWindow::setupDB()
{
    auto db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DB_NAME);
    if(!db.open()) {
        qDebug() << "DB.open() failed";
        qApp->quit();
    }

    QSqlQuery query(db);
    if(!query.exec(CREATE_TABLE_QUERY)) {
        qDebug() << "table not found and failed to create";
    }
}

QString MainWindow::getInsertTaskQuery(QList<QStandardItem *> values)
{
    return QString("INSERT INTO %1 VALUES(NULL, '%2', '%3', '%4')")
            .arg(TABLE_NAME,
                 values[0]->text(),
                 values[1]->text(),
                 values[2]->text());
}
