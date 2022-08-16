#ifndef SHORTCUTSPREFSDIALOG_H
#define SHORTCUTSPREFSDIALOG_H

#include <QDialog>

#include <utility>

namespace Ui {
class ShortcutsPrefsDialog;
}

class ShortcutsPrefsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShortcutsPrefsDialog(QWidget *parent = nullptr);
    ~ShortcutsPrefsDialog();

    std::pair<int, Qt::KeyboardModifiers> getSaveFileActionShortcut();
    std::pair<int, Qt::KeyboardModifiers> getOpenFileActionShortcut();
private:
    Ui::ShortcutsPrefsDialog *ui;
};

#endif // SHORTCUTSPREFSDIALOG_H
