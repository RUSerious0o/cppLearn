/********************************************************************************
** Form generated from reading UI file 'filesearchdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESEARCHDIALOG_H
#define UI_FILESEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FileSearchDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *searchButton;
    QDialogButtonBox *buttonBox;
    QLineEdit *requestLineEdit;
    QTableView *searchResultView;
    QLabel *selectedDirectoryLabel;

    void setupUi(QDialog *FileSearchDialog)
    {
        if (FileSearchDialog->objectName().isEmpty())
            FileSearchDialog->setObjectName(QString::fromUtf8("FileSearchDialog"));
        FileSearchDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(FileSearchDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        searchButton = new QPushButton(FileSearchDialog);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        gridLayout->addWidget(searchButton, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(FileSearchDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 2);

        requestLineEdit = new QLineEdit(FileSearchDialog);
        requestLineEdit->setObjectName(QString::fromUtf8("requestLineEdit"));

        gridLayout->addWidget(requestLineEdit, 1, 0, 1, 1);

        searchResultView = new QTableView(FileSearchDialog);
        searchResultView->setObjectName(QString::fromUtf8("searchResultView"));

        gridLayout->addWidget(searchResultView, 3, 0, 1, 2);

        selectedDirectoryLabel = new QLabel(FileSearchDialog);
        selectedDirectoryLabel->setObjectName(QString::fromUtf8("selectedDirectoryLabel"));

        gridLayout->addWidget(selectedDirectoryLabel, 0, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(FileSearchDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FileSearchDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FileSearchDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FileSearchDialog);
    } // setupUi

    void retranslateUi(QDialog *FileSearchDialog)
    {
        FileSearchDialog->setWindowTitle(QApplication::translate("FileSearchDialog", "Dialog", nullptr));
        searchButton->setText(QString());
        selectedDirectoryLabel->setText(QApplication::translate("FileSearchDialog", "directory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileSearchDialog: public Ui_FileSearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESEARCHDIALOG_H
