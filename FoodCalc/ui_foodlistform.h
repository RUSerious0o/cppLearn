/********************************************************************************
** Form generated from reading UI file 'foodlistform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOODLISTFORM_H
#define UI_FOODLISTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FoodListForm
{
public:
    QVBoxLayout *verticalLayout_3;
    QLineEdit *foodFilterlineEdit;
    QHBoxLayout *sortButtonsLayout;
    QPushButton *sortByNameButton;
    QPushButton *sortByPbutton;
    QPushButton *sortByFbutton;
    QPushButton *sortByCHbutton;
    QPushButton *sortByCalButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *FoodListForm)
    {
        if (FoodListForm->objectName().isEmpty())
            FoodListForm->setObjectName(QString::fromUtf8("FoodListForm"));
        FoodListForm->resize(664, 581);
        verticalLayout_3 = new QVBoxLayout(FoodListForm);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        foodFilterlineEdit = new QLineEdit(FoodListForm);
        foodFilterlineEdit->setObjectName(QString::fromUtf8("foodFilterlineEdit"));

        verticalLayout_3->addWidget(foodFilterlineEdit);

        sortButtonsLayout = new QHBoxLayout();
        sortButtonsLayout->setObjectName(QString::fromUtf8("sortButtonsLayout"));
        sortByNameButton = new QPushButton(FoodListForm);
        sortByNameButton->setObjectName(QString::fromUtf8("sortByNameButton"));
        sortByNameButton->setMinimumSize(QSize(300, 0));

        sortButtonsLayout->addWidget(sortByNameButton);

        sortByPbutton = new QPushButton(FoodListForm);
        sortByPbutton->setObjectName(QString::fromUtf8("sortByPbutton"));
        sortByPbutton->setCheckable(false);

        sortButtonsLayout->addWidget(sortByPbutton);

        sortByFbutton = new QPushButton(FoodListForm);
        sortByFbutton->setObjectName(QString::fromUtf8("sortByFbutton"));

        sortButtonsLayout->addWidget(sortByFbutton);

        sortByCHbutton = new QPushButton(FoodListForm);
        sortByCHbutton->setObjectName(QString::fromUtf8("sortByCHbutton"));

        sortButtonsLayout->addWidget(sortByCHbutton);

        sortByCalButton = new QPushButton(FoodListForm);
        sortByCalButton->setObjectName(QString::fromUtf8("sortByCalButton"));

        sortButtonsLayout->addWidget(sortByCalButton);

        sortButtonsLayout->setStretch(0, 4);
        sortButtonsLayout->setStretch(1, 1);
        sortButtonsLayout->setStretch(2, 1);
        sortButtonsLayout->setStretch(3, 1);
        sortButtonsLayout->setStretch(4, 1);

        verticalLayout_3->addLayout(sortButtonsLayout);

        scrollArea = new QScrollArea(FoodListForm);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 644, 504));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);

        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        verticalLayout_3->setStretch(2, 1);

        retranslateUi(FoodListForm);

        QMetaObject::connectSlotsByName(FoodListForm);
    } // setupUi

    void retranslateUi(QWidget *FoodListForm)
    {
        FoodListForm->setWindowTitle(QApplication::translate("FoodListForm", "Form", nullptr));
        foodFilterlineEdit->setPlaceholderText(QApplication::translate("FoodListForm", "\320\235\320\260\321\207\320\275\320\270\321\202\320\265 \320\262\320\262\320\276\320\264\320\270\321\202\321\214 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        sortByNameButton->setText(QApplication::translate("FoodListForm", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        sortByPbutton->setText(QApplication::translate("FoodListForm", "\320\221\320\265\320\273\320\272\320\270", nullptr));
        sortByFbutton->setText(QApplication::translate("FoodListForm", "\320\226\320\270\321\200\321\213", nullptr));
        sortByCHbutton->setText(QApplication::translate("FoodListForm", "\320\243\320\263\320\273\320\265\320\262\320\276\320\264\321\213", nullptr));
        sortByCalButton->setText(QApplication::translate("FoodListForm", "\320\232\320\272\320\260\320\273 / 100 \320\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FoodListForm: public Ui_FoodListForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOODLISTFORM_H
