#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickItem>
#include <QStandardItemModel>
#include <QTableView>
#include <QString>

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

    int getTasksCount();
    QList<QStandardItem*> takeTask(int taskId);
public slots:
    void onAddTaskRequested();

private:
    Ui::MainWindow *ui;
    QQuickItem *inputInterfaceRoot;
    QStandardItemModel *model;
    QTableView *tasksTable;

    const QString ERROR_MESSAGE = "Неверно введены данные задачи!";
    const QString SAVE_FILE_NAME = "tasks.dat";
    const QString TASK_NAME_INPUT_WIDGET = "taskNameInput";
    const QString TASK_DEADLINE_INPUT_WIDGET = "selectedDateInput";
    const QString TASK_PROGRESS_WIDGET = "progressSlider";
    const QString TASK_PROGRESS_WIDGET_TEXT = "progressSliderTextValue";
    const QString DELIMITER = " ||| ";

    void setupInputInterface();
    void setupTaskList();

    void saveValues();
    void loadValues();
};
#endif // MAINWINDOW_H
