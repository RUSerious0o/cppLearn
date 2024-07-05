/********************************************************************************
** Form generated from reading UI file 'helpDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *helpLabel;

    void setupUi(QDialog *HelpDialog)
    {
        if (HelpDialog->objectName().isEmpty())
            HelpDialog->setObjectName(QString::fromUtf8("HelpDialog"));
        HelpDialog->resize(404, 144);
        verticalLayoutWidget = new QWidget(HelpDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 401, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        helpLabel = new QLabel(verticalLayoutWidget);
        helpLabel->setObjectName(QString::fromUtf8("helpLabel"));
        helpLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        helpLabel->setWordWrap(true);

        verticalLayout->addWidget(helpLabel);


        retranslateUi(HelpDialog);

        QMetaObject::connectSlotsByName(HelpDialog);
    } // setupUi

    void retranslateUi(QDialog *HelpDialog)
    {
        HelpDialog->setWindowTitle(QApplication::translate("HelpDialog", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        helpLabel->setText(QApplication::translate("HelpDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpDialog: public Ui_HelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
