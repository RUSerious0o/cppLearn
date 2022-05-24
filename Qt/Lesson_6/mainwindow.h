#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTranslator>
#include <QFileSystemModel>

class HelpDialog;
class ShortcutsPrefsDialog;
class FileExplorer;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupHelp();

private slots:
    void onSaveFileActionTriggered();
    void onOpenFileActionTriggered();
    void onReadOnlyOpenFileActionTriggered();
    void onShowHelpTriggered();
    void onNewFileTriggered();
    void onShortcutsDialogShowAction();
    void onTranslationChangeTriggered();
    void onFileExplorerItemSelected(const QString& filePath);
    void onChangeThemeTriggered();
    void onPrintTriggered();

private:
    class ShortcutsEventFilter : public QObject
    {
    public:
        explicit ShortcutsEventFilter(QObject *parent = nullptr);

    protected:
        bool eventFilter(QObject *obj, QEvent *event) override;
    };

    enum EditMode { ReadOnly, Normal };

    enum Theme { Dark, Light };

private:
    Ui::MainWindow *ui;
    HelpDialog *help;
    ShortcutsPrefsDialog *shortcutsDialog;
    ShortcutsEventFilter *shortcutsEventFilter;
    QTranslator translator;
    QString currentTranslation;
    FileExplorer *fileExplorer;
    Theme currentTheme;

    const QString SAVE_DIALOG_CAPTION = "Сохранить файл";
    const QString OPEN_DIALOG_CAPTION = "Открыть файл";
    const QString OPEN_SAVE_DIALOG_FILTER = "Текстовый файл (*.txt)";
    const QString FILES_DEFAULT_DIR = "./files";
    const QString ENGLISH_TR = "./QtLanguage_en";
    const QString RUSSIAN_TR = "./QtLanguage_ru";
    const QString ENGLISH_HELP = ":/help/help_en.txt";
    const QString RUSSIAN_HELP = ":/help/help.txt";
    const QString DARK_THEME = ":/Qss/dark.qss";
    const QString LIGHT_THEME = ":/Qss/light.qss";

    void setMode(EditMode mode);
    void setTranslation(QString translation);
    void expandCurrentDirectory();

    std::map<Theme, QString> themes {
        { Dark,  DARK_THEME},
        { Light, LIGHT_THEME}
    };
    void setTheme(Theme theme);
};
#endif // MAINWINDOW_H
