/********************************************************************************
** Form generated from reading UI file 'ingredientsSummaryForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INGREDIENTSSUMMARYFORM_H
#define UI_INGREDIENTSSUMMARYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IngredientsSummaryForm
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addIngredientButton;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *ingredientNameInput;
    QPushButton *deleteIngredientButton;
    QHBoxLayout *PFCInputHorizontalLayout;
    QLabel *proteinsLabel;
    QLineEdit *proteinsInput;
    QLabel *fatsLabel;
    QLineEdit *fatsInput;
    QLabel *carbohsLabel;
    QLineEdit *carbohsInput;
    QPushButton *ingredientCommitButton;

    void setupUi(QWidget *IngredientsSummaryForm)
    {
        if (IngredientsSummaryForm->objectName().isEmpty())
            IngredientsSummaryForm->setObjectName(QString::fromUtf8("IngredientsSummaryForm"));
        IngredientsSummaryForm->resize(647, 171);
        verticalLayout = new QVBoxLayout(IngredientsSummaryForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addIngredientButton = new QPushButton(IngredientsSummaryForm);
        addIngredientButton->setObjectName(QString::fromUtf8("addIngredientButton"));

        horizontalLayout->addWidget(addIngredientButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        ingredientNameInput = new QLineEdit(IngredientsSummaryForm);
        ingredientNameInput->setObjectName(QString::fromUtf8("ingredientNameInput"));

        horizontalLayout_2->addWidget(ingredientNameInput);

        deleteIngredientButton = new QPushButton(IngredientsSummaryForm);
        deleteIngredientButton->setObjectName(QString::fromUtf8("deleteIngredientButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deleteIngredientButton->sizePolicy().hasHeightForWidth());
        deleteIngredientButton->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(deleteIngredientButton);


        verticalLayout->addLayout(horizontalLayout_2);

        PFCInputHorizontalLayout = new QHBoxLayout();
        PFCInputHorizontalLayout->setObjectName(QString::fromUtf8("PFCInputHorizontalLayout"));
        proteinsLabel = new QLabel(IngredientsSummaryForm);
        proteinsLabel->setObjectName(QString::fromUtf8("proteinsLabel"));

        PFCInputHorizontalLayout->addWidget(proteinsLabel);

        proteinsInput = new QLineEdit(IngredientsSummaryForm);
        proteinsInput->setObjectName(QString::fromUtf8("proteinsInput"));
        proteinsInput->setMaxLength(4);

        PFCInputHorizontalLayout->addWidget(proteinsInput);

        fatsLabel = new QLabel(IngredientsSummaryForm);
        fatsLabel->setObjectName(QString::fromUtf8("fatsLabel"));

        PFCInputHorizontalLayout->addWidget(fatsLabel);

        fatsInput = new QLineEdit(IngredientsSummaryForm);
        fatsInput->setObjectName(QString::fromUtf8("fatsInput"));
        fatsInput->setMaxLength(4);

        PFCInputHorizontalLayout->addWidget(fatsInput);

        carbohsLabel = new QLabel(IngredientsSummaryForm);
        carbohsLabel->setObjectName(QString::fromUtf8("carbohsLabel"));

        PFCInputHorizontalLayout->addWidget(carbohsLabel);

        carbohsInput = new QLineEdit(IngredientsSummaryForm);
        carbohsInput->setObjectName(QString::fromUtf8("carbohsInput"));
        carbohsInput->setMaxLength(4);

        PFCInputHorizontalLayout->addWidget(carbohsInput);


        verticalLayout->addLayout(PFCInputHorizontalLayout);

        ingredientCommitButton = new QPushButton(IngredientsSummaryForm);
        ingredientCommitButton->setObjectName(QString::fromUtf8("ingredientCommitButton"));

        verticalLayout->addWidget(ingredientCommitButton);


        retranslateUi(IngredientsSummaryForm);

        QMetaObject::connectSlotsByName(IngredientsSummaryForm);
    } // setupUi

    void retranslateUi(QWidget *IngredientsSummaryForm)
    {
        IngredientsSummaryForm->setWindowTitle(QApplication::translate("IngredientsSummaryForm", "Form", nullptr));
        addIngredientButton->setText(QApplication::translate("IngredientsSummaryForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \320\277\321\200\320\276\320\264\321\203\320\272\321\202", nullptr));
        ingredientNameInput->setPlaceholderText(QApplication::translate("IngredientsSummaryForm", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\260", nullptr));
        deleteIngredientButton->setText(QApplication::translate("IngredientsSummaryForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        proteinsLabel->setText(QApplication::translate("IngredientsSummaryForm", "\320\221\320\265\320\273\320\272\320\270", nullptr));
        fatsLabel->setText(QApplication::translate("IngredientsSummaryForm", "\320\226\320\270\321\200\321\213", nullptr));
        carbohsLabel->setText(QApplication::translate("IngredientsSummaryForm", "\320\243\320\263\320\273\320\265\320\262\320\276\320\264\321\213", nullptr));
        ingredientCommitButton->setText(QApplication::translate("IngredientsSummaryForm", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IngredientsSummaryForm: public Ui_IngredientsSummaryForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INGREDIENTSSUMMARYFORM_H
