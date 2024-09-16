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

private slots:
    void onAddTaskRequested();

private:
    Ui::MainWindow *ui;
    QQuickItem *inputInterfaceRoot;
    QStandardItemModel *model;
    QTableView *tasksTable;

    const QString SAVE_FILE_NAME = "tasks.dat";

    void setupInputInterface();
    void setupTaskList();

    void saveValues();
    void loadValues();
};
#endif // MAINWINDOW_H
