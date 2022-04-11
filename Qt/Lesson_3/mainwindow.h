#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    void resizeEvent(QResizeEvent *) override;

private slots:
    void onSaveFileActionTriggered();
    void onOpenFileActionTriggered();

private:
    Ui::MainWindow *ui;

    QString SAVE_DIALOG_CAPTION = "Сохранить файл";
    QString OPEN_DIALOG_CAPTION = "Открыть файл";
    QString OPEN_SAVE_DIALOG_FILTER = "Текстовый файл (*.txt)";
    QString FILES_DEFAULT_DIR = "./files";
};
#endif // MAINWINDOW_H
