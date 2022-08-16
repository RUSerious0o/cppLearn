#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTranslator>
#include <QFileSystemModel>
#include <QTextCharFormat>

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
    void onChangeFontActionTriggered();
    void onCopyFormatActionTriggered();
    void onPasteFormatActionTriggered();
    void onTextAlignLeftActionTriggered();
    void onTextAlignRightActionTriggered();
    void onTextAlignCenterActionTriggered();

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
    std::pair<bool, QTextCharFormat> storedCharFormat;

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

    const QString FONT_ICON_PATH = ":/icons/font_icon.png";
    const QString FONT_ICON_TOOLTIP = "Изменить шрифт";
    const QString SAVE_FORMAT_ICON_PATH = ":/icons/font_copy_icon.png";
    const QString SAVE_FORMAT_ICON_TOOLTIP = "Скопировать форматирование";
    const QString PASTE_FORMAT_ICON_PATH = ":/icons/font_paste_icon.png";
    const QString PASTE_FORMAT_ICON_TOOLTIP = "Применить форматирование";
    const QString TEXT_ALIGN_LEFT_ICON_PATH = ":/icons/text_align_left_icon.png";
    const QString TEXT_ALIGN_LEFT_TOOLTIP = "Выровнять по левому краю";
    const QString TEXT_ALIGN_RIGHT_ICON_PATH = ":/icons/text_align_right_icon.png";
    const QString TEXT_ALIGN_RIGHT_TOOLTIP = "Выровнять по правому краю";
    const QString TEXT_ALIGN_CENTER_ICON_PATH = ":/icons/text_align_center_icon.png";
    const QString TEXT_ALIGN_CENTER_TOOLTIP = "Выровнять по центру";

    void setMode(EditMode mode);
    void setTranslation(QString translation);
    void expandCurrentDirectory();
    void setupToolBar();

    std::map<Theme, QString> themes {
        { Dark,  DARK_THEME},
        { Light, LIGHT_THEME}
    };
    void setTheme(Theme theme);
};
#endif // MAINWINDOW_H
