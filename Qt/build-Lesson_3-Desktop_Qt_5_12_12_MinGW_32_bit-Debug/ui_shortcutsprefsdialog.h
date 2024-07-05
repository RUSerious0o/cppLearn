/********************************************************************************
** Form generated from reading UI file 'shortcutsprefsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTCUTSPREFSDIALOG_H
#define UI_SHORTCUTSPREFSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShortcutsPrefsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QRadioButton *saveOnCtrlRadio;
    QRadioButton *saveOnFRadio;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_2;
    QRadioButton *openOnCtrlRadio;
    QRadioButton *openOnFRadio;

    void setupUi(QDialog *ShortcutsPrefsDialog)
    {
        if (ShortcutsPrefsDialog->objectName().isEmpty())
            ShortcutsPrefsDialog->setObjectName(QString::fromUtf8("ShortcutsPrefsDialog"));
        ShortcutsPrefsDialog->resize(380, 146);
        buttonBox = new QDialogButtonBox(ShortcutsPrefsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(0, 110, 371, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(ShortcutsPrefsDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 371, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        saveOnCtrlRadio = new QRadioButton(groupBox);
        saveOnCtrlRadio->setObjectName(QString::fromUtf8("saveOnCtrlRadio"));
        saveOnCtrlRadio->setGeometry(QRect(10, 20, 82, 19));
        saveOnCtrlRadio->setChecked(true);
        saveOnFRadio = new QRadioButton(groupBox);
        saveOnFRadio->setObjectName(QString::fromUtf8("saveOnFRadio"));
        saveOnFRadio->setGeometry(QRect(90, 20, 117, 19));

        horizontalLayout->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox_2 = new QGroupBox(verticalLayoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        openOnCtrlRadio = new QRadioButton(groupBox_2);
        openOnCtrlRadio->setObjectName(QString::fromUtf8("openOnCtrlRadio"));
        openOnCtrlRadio->setGeometry(QRect(10, 20, 85, 19));
        openOnCtrlRadio->setChecked(true);
        openOnFRadio = new QRadioButton(groupBox_2);
        openOnFRadio->setObjectName(QString::fromUtf8("openOnFRadio"));
        openOnFRadio->setGeometry(QRect(90, 20, 117, 19));

        horizontalLayout_2->addWidget(groupBox_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ShortcutsPrefsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ShortcutsPrefsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ShortcutsPrefsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ShortcutsPrefsDialog);
    } // setupUi

    void retranslateUi(QDialog *ShortcutsPrefsDialog)
    {
        ShortcutsPrefsDialog->setWindowTitle(QApplication::translate("ShortcutsPrefsDialog", "\320\235\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\263\320\276\321\200\321\217\321\207\320\270\321\205 \320\272\320\273\320\260\320\262\320\270\321\210", nullptr));
        groupBox->setTitle(QApplication::translate("ShortcutsPrefsDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260", nullptr));
        saveOnCtrlRadio->setText(QApplication::translate("ShortcutsPrefsDialog", "Ctrl + S", nullptr));
        saveOnFRadio->setText(QApplication::translate("ShortcutsPrefsDialog", "F2", nullptr));
        groupBox_2->setTitle(QApplication::translate("ShortcutsPrefsDialog", "\320\236\321\202\320\272\321\200\321\213\321\202\320\270\320\265 \321\204\320\260\320\271\320\273\320\260", nullptr));
        openOnCtrlRadio->setText(QApplication::translate("ShortcutsPrefsDialog", "Ctrl + O", nullptr));
        openOnFRadio->setText(QApplication::translate("ShortcutsPrefsDialog", "F3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShortcutsPrefsDialog: public Ui_ShortcutsPrefsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTCUTSPREFSDIALOG_H
