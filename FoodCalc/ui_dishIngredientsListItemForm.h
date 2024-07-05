/********************************************************************************
** Form generated from reading UI file 'dishIngredientsListItemForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISHINGREDIENTSLISTITEMFORM_H
#define UI_DISHINGREDIENTSLISTITEMFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DishIngredientsListItemForm
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *nameLabel;
    QLabel *weightLabel;
    QLabel *label;

    void setupUi(QWidget *DishIngredientsListItemForm)
    {
        if (DishIngredientsListItemForm->objectName().isEmpty())
            DishIngredientsListItemForm->setObjectName(QString::fromUtf8("DishIngredientsListItemForm"));
        DishIngredientsListItemForm->resize(400, 55);
        horizontalLayout = new QHBoxLayout(DishIngredientsListItemForm);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(DishIngredientsListItemForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/pics/edit_icon_48.png")));
        label_2->setScaledContents(true);

        horizontalLayout->addWidget(label_2);

        nameLabel = new QLabel(DishIngredientsListItemForm);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        horizontalLayout->addWidget(nameLabel);

        weightLabel = new QLabel(DishIngredientsListItemForm);
        weightLabel->setObjectName(QString::fromUtf8("weightLabel"));
        weightLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(weightLabel);

        label = new QLabel(DishIngredientsListItemForm);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        retranslateUi(DishIngredientsListItemForm);

        QMetaObject::connectSlotsByName(DishIngredientsListItemForm);
    } // setupUi

    void retranslateUi(QWidget *DishIngredientsListItemForm)
    {
        DishIngredientsListItemForm->setWindowTitle(QApplication::translate("DishIngredientsListItemForm", "Form", nullptr));
        label_2->setText(QString());
        nameLabel->setText(QApplication::translate("DishIngredientsListItemForm", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\320\260", nullptr));
        weightLabel->setText(QApplication::translate("DishIngredientsListItemForm", "\320\274\320\260\321\201\321\201\320\260 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\320\260,", nullptr));
        label->setText(QApplication::translate("DishIngredientsListItemForm", "\320\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DishIngredientsListItemForm: public Ui_DishIngredientsListItemForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISHINGREDIENTSLISTITEMFORM_H
