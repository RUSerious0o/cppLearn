#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTranslator>

class HelpDialog;
class ShortcutsPrefsDialog;

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

    void setHelpFileContents();

private slots:
    void onSaveFileActionTriggered();
    void onOpenFileActionTriggered();
    void onReadOnlyOpenFileActionTriggered();
    void onShowHelpTriggered();
    void onNewFileTriggered();
    void onShortcutsDialogShowAction();
    void onTranslationChangeTriggered();

private:
    class ShortcutsEventFilter : public QObject
    {
    public:
        explicit ShortcutsEventFilter(QObject *parent = nullptr);

    protected:
        bool eventFilter(QObject *obj, QEvent *event) override;
    };

    enum EditMode { ReadOnly, Normal };

private:
    Ui::MainWindow *ui;
    HelpDialog *help;
    ShortcutsPrefsDialog *shortcutsDialog;
    ShortcutsEventFilter *shortcutsEventFilter;
    QTranslator translator;
    QString currentTranslation;

    const QString SAVE_DIALOG_CAPTION = "Сохранить файл";
    const QString OPEN_DIALOG_CAPTION = "Открыть файл";
    const QString OPEN_SAVE_DIALOG_FILTER = "Текстовый файл (*.txt)";
    const QString FILES_DEFAULT_DIR = "./files";
    const QString ENGLISH_TR = "./QtLanguage_en";
    const QString RUSSIAN_TR = "./QtLanguage_ru";
    const QString ENGLISH_HELP = ":/help/help_en.txt";
    const QString RUSSIAN_HELP = ":/help/help.txt";

    void setMode(EditMode mode);
    void setTranslation(QString translation);
};
#endif // MAINWINDOW_H
