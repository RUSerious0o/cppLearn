#include "shortcutsprefsdialog.h"
#include "ui_shortcutsprefsdialog.h"

#include <utility>

ShortcutsPrefsDialog::ShortcutsPrefsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShortcutsPrefsDialog)
{
    ui->setupUi(this);
}

ShortcutsPrefsDialog::~ShortcutsPrefsDialog()
{
    delete ui;
}

std::pair<int, Qt::KeyboardModifiers> ShortcutsPrefsDialog::getSaveFileActionShortcut()
{
    if(ui->saveOnCtrlRadio->isChecked()) {
        return std::pair<int, Qt::KeyboardModifiers>{ Qt::Key_S, Qt::ControlModifier };
    } else {
        return std::pair<int, Qt::KeyboardModifiers>{ Qt::Key_F2, Qt::NoModifier };
    }
}

std::pair<int, Qt::KeyboardModifiers> ShortcutsPrefsDialog::getOpenFileActionShortcut()
{
    if(ui->openOnCtrlRadio->isChecked()) {
        return std::pair<int, Qt::KeyboardModifiers>{ Qt::Key_O, Qt::ControlModifier };
    } else {
        return std::pair<int, Qt::KeyboardModifiers>{ Qt::Key_F3, Qt::NoModifier };
    }
}
