/********************************************************************************
** Form generated from reading UI file 'dishEditForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISHEDITFORM_H
#define UI_DISHEDITFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DishEditForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *deleteDishButton;
    QHBoxLayout *horizontalLayout;
    QLineEdit *dishNameInput;
    QPushButton *dishNameCommitButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *PHintLabel;
    QLabel *proteinsLabel;
    QLabel *FHintLabel;
    QLabel *fatsLabel;
    QLabel *CHintLabel;
    QLabel *carbohsLabel;
    QLabel *label_4;
    QLabel *caloriesLabel;
    QHBoxLayout *ingredientsLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *selectedIngredientLabel;
    QLineEdit *ingredientWeightInput;
    QPushButton *ingredientCommitButton;
    QPushButton *dishIngredientDeleteButton;
    QVBoxLayout *dishIngredientsLayout;

    void setupUi(QWidget *DishEditForm)
    {
        if (DishEditForm->objectName().isEmpty())
            DishEditForm->setObjectName(QString::fromUtf8("DishEditForm"));
        DishEditForm->resize(646, 192);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DishEditForm->sizePolicy().hasHeightForWidth());
        DishEditForm->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(DishEditForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(DishEditForm);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        deleteDishButton = new QPushButton(DishEditForm);
        deleteDishButton->setObjectName(QString::fromUtf8("deleteDishButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(deleteDishButton->sizePolicy().hasHeightForWidth());
        deleteDishButton->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(deleteDishButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dishNameInput = new QLineEdit(DishEditForm);
        dishNameInput->setObjectName(QString::fromUtf8("dishNameInput"));

        horizontalLayout->addWidget(dishNameInput);

        dishNameCommitButton = new QPushButton(DishEditForm);
        dishNameCommitButton->setObjectName(QString::fromUtf8("dishNameCommitButton"));
        sizePolicy1.setHeightForWidth(dishNameCommitButton->sizePolicy().hasHeightForWidth());
        dishNameCommitButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(dishNameCommitButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        PHintLabel = new QLabel(DishEditForm);
        PHintLabel->setObjectName(QString::fromUtf8("PHintLabel"));

        horizontalLayout_4->addWidget(PHintLabel);

        proteinsLabel = new QLabel(DishEditForm);
        proteinsLabel->setObjectName(QString::fromUtf8("proteinsLabel"));

        horizontalLayout_4->addWidget(proteinsLabel);

        FHintLabel = new QLabel(DishEditForm);
        FHintLabel->setObjectName(QString::fromUtf8("FHintLabel"));

        horizontalLayout_4->addWidget(FHintLabel);

        fatsLabel = new QLabel(DishEditForm);
        fatsLabel->setObjectName(QString::fromUtf8("fatsLabel"));

        horizontalLayout_4->addWidget(fatsLabel);

        CHintLabel = new QLabel(DishEditForm);
        CHintLabel->setObjectName(QString::fromUtf8("CHintLabel"));

        horizontalLayout_4->addWidget(CHintLabel);

        carbohsLabel = new QLabel(DishEditForm);
        carbohsLabel->setObjectName(QString::fromUtf8("carbohsLabel"));

        horizontalLayout_4->addWidget(carbohsLabel);

        label_4 = new QLabel(DishEditForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        caloriesLabel = new QLabel(DishEditForm);
        caloriesLabel->setObjectName(QString::fromUtf8("caloriesLabel"));

        horizontalLayout_4->addWidget(caloriesLabel);


        verticalLayout->addLayout(horizontalLayout_4);

        ingredientsLayout = new QHBoxLayout();
        ingredientsLayout->setObjectName(QString::fromUtf8("ingredientsLayout"));
        label_2 = new QLabel(DishEditForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        ingredientsLayout->addWidget(label_2);


        verticalLayout->addLayout(ingredientsLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        selectedIngredientLabel = new QLabel(DishEditForm);
        selectedIngredientLabel->setObjectName(QString::fromUtf8("selectedIngredientLabel"));

        horizontalLayout_3->addWidget(selectedIngredientLabel);

        ingredientWeightInput = new QLineEdit(DishEditForm);
        ingredientWeightInput->setObjectName(QString::fromUtf8("ingredientWeightInput"));
        ingredientWeightInput->setMaxLength(5);

        horizontalLayout_3->addWidget(ingredientWeightInput);

        ingredientCommitButton = new QPushButton(DishEditForm);
        ingredientCommitButton->setObjectName(QString::fromUtf8("ingredientCommitButton"));
        sizePolicy1.setHeightForWidth(ingredientCommitButton->sizePolicy().hasHeightForWidth());
        ingredientCommitButton->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(ingredientCommitButton);

        dishIngredientDeleteButton = new QPushButton(DishEditForm);
        dishIngredientDeleteButton->setObjectName(QString::fromUtf8("dishIngredientDeleteButton"));
        sizePolicy1.setHeightForWidth(dishIngredientDeleteButton->sizePolicy().hasHeightForWidth());
        dishIngredientDeleteButton->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(dishIngredientDeleteButton);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        dishIngredientsLayout = new QVBoxLayout();
        dishIngredientsLayout->setObjectName(QString::fromUtf8("dishIngredientsLayout"));

        verticalLayout->addLayout(dishIngredientsLayout);


        retranslateUi(DishEditForm);

        QMetaObject::connectSlotsByName(DishEditForm);
    } // setupUi

    void retranslateUi(QWidget *DishEditForm)
    {
        DishEditForm->setWindowTitle(QApplication::translate("DishEditForm", "Form", nullptr));
        label->setText(QApplication::translate("DishEditForm", "\320\240\320\265\321\206\320\265\320\277\321\202", nullptr));
        deleteDishButton->setText(QApplication::translate("DishEditForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        dishNameInput->setPlaceholderText(QApplication::translate("DishEditForm", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\261\320\273\321\216\320\264\320\260", nullptr));
        dishNameCommitButton->setText(QApplication::translate("DishEditForm", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        PHintLabel->setText(QApplication::translate("DishEditForm", "\320\221\320\265\320\273\320\272\320\270:", nullptr));
        proteinsLabel->setText(QApplication::translate("DishEditForm", "0", nullptr));
        FHintLabel->setText(QApplication::translate("DishEditForm", "\320\226\320\270\321\200\321\213:", nullptr));
        fatsLabel->setText(QApplication::translate("DishEditForm", "0", nullptr));
        CHintLabel->setText(QApplication::translate("DishEditForm", "\320\243\320\263\320\273\320\265\320\262\320\276\320\264\321\213", nullptr));
        carbohsLabel->setText(QApplication::translate("DishEditForm", "0", nullptr));
        label_4->setText(QApplication::translate("DishEditForm", "\320\232\320\272\320\260\320\273/100 \320\263", nullptr));
        caloriesLabel->setText(QApplication::translate("DishEditForm", "0", nullptr));
        label_2->setText(QApplication::translate("DishEditForm", "\320\230\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\321\213:", nullptr));
        selectedIngredientLabel->setText(QApplication::translate("DishEditForm", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202", nullptr));
        ingredientWeightInput->setPlaceholderText(QApplication::translate("DishEditForm", "\320\274\320\260\321\201\321\201\320\260, \320\263", nullptr));
        ingredientCommitButton->setText(QApplication::translate("DishEditForm", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        dishIngredientDeleteButton->setText(QApplication::translate("DishEditForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DishEditForm: public Ui_DishEditForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISHEDITFORM_H
