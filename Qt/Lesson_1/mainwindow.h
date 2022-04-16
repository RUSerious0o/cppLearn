#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

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
    void on_calcButton_1_released();

    void on_calcButton_2_released();

    void on_mergeTextButton_released();

    void on_perlaceTextButton_released();

    void on_htmlButton_released();

private:
    Ui::MainWindow *ui;

    double calcD();

    void convertInputValue(QLineEdit* lineEdit);

    double calculateTriangleSide();
};
#endif // MAINWINDOW_H
