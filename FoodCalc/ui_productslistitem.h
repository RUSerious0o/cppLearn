/********************************************************************************
** Form generated from reading UI file 'productslistitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTSLISTITEM_H
#define UI_PRODUCTSLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductsListItem
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *name;
    QLabel *protein;
    QLabel *fats;
    QLabel *carbohs;
    QLabel *calories;

    void setupUi(QWidget *ProductsListItem)
    {
        if (ProductsListItem->objectName().isEmpty())
            ProductsListItem->setObjectName(QString::fromUtf8("ProductsListItem"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ProductsListItem->sizePolicy().hasHeightForWidth());
        ProductsListItem->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(ProductsListItem);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        name = new QLabel(ProductsListItem);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMinimumSize(QSize(300, 0));

        horizontalLayout->addWidget(name);

        protein = new QLabel(ProductsListItem);
        protein->setObjectName(QString::fromUtf8("protein"));
        protein->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(protein);

        fats = new QLabel(ProductsListItem);
        fats->setObjectName(QString::fromUtf8("fats"));
        fats->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(fats);

        carbohs = new QLabel(ProductsListItem);
        carbohs->setObjectName(QString::fromUtf8("carbohs"));
        carbohs->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(carbohs);

        calories = new QLabel(ProductsListItem);
        calories->setObjectName(QString::fromUtf8("calories"));
        calories->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(calories);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);

        retranslateUi(ProductsListItem);

        QMetaObject::connectSlotsByName(ProductsListItem);
    } // setupUi

    void retranslateUi(QWidget *ProductsListItem)
    {
        ProductsListItem->setWindowTitle(QApplication::translate("ProductsListItem", "Form", nullptr));
        name->setText(QApplication::translate("ProductsListItem", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\260", nullptr));
        protein->setText(QApplication::translate("ProductsListItem", "\320\221", nullptr));
        fats->setText(QApplication::translate("ProductsListItem", "\320\226", nullptr));
        carbohs->setText(QApplication::translate("ProductsListItem", "\320\243", nullptr));
        calories->setText(QApplication::translate("ProductsListItem", "\320\232\320\272\320\260\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductsListItem: public Ui_ProductsListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTSLISTITEM_H
