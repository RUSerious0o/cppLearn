#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickItem>
#include <QStandardItemModel>
#include <QTableView>
#include <QString>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setTaskName(const QString& taskName);
    void setTaskDeadline(const QDate& date);
    void setTaskProgress(int progress);

public slots:
    void onAddTaskRequested();

private:
    Ui::MainWindow *ui;
    QQuickItem *inputInterfaceRoot;    
    QTableView *tasksTable;
    QSqlTableModel *dbModel;

    const QString ERROR_MESSAGE = "Неверно введены данные задачи!";
    const QString SAVE_FILE_NAME = "tasks.dat";
    const QString TASK_NAME_INPUT_WIDGET = "taskNameInput";
    const QString TASK_DEADLINE_INPUT_WIDGET = "selectedDateInput";
    const QString TASK_PROGRESS_WIDGET = "progressSlider";
    const QString TASK_PROGRESS_WIDGET_TEXT = "progressSliderTextValue";
    const QString DELIMITER = " ||| ";

    const QString DB_NAME = "./tasks.db";
    const QString TABLE_NAME = "tasks";
    const QString CREATE_TABLE_QUERY = QString("CREATE TABLE IF NOT EXISTS '%1' (%2, %3, %4, %5)")
            .arg(TABLE_NAME,
                 "'id' INTEGER PRIMARY KEY AUTOINCREMENT",
                 "'taskDescription' VARCHAR(2048) NOT NULL",
                 "'deadline' VARCHAR(10) NOT NULL",
                 "'progress' INT NOT NULL");

    void setupInputInterface();
    void setupTaskList();
    void setupDB();

    QString getInsertTaskQuery(QList<QStandardItem*>);
};
#endif // MAINWINDOW_H
