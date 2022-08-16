#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

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
    void on_textEdit_textChanged();

    void on_pushButton_released();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_2_released();

    void on_pushButton_3_released();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *listModel;
    QStandardItemModel *tableModel;
    QStandardItemModel *tableHeaderModel;

    void setupList();
    void setupTable();
};
#endif // MAINWINDOW_H
