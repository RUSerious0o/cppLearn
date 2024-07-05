/********************************************************************************
** Form generated from reading UI file 'dailynutrition.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAILYNUTRITION_H
#define UI_DAILYNUTRITION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DailyNutrition
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *dateLabel;
    QPushButton *showCalendarButton;
    QPushButton *refreshDateButton;
    QLabel *label_11;
    QComboBox *hoursComboBox;
    QLabel *selectedTimeLabel;
    QComboBox *minutesComboBox;
    QPushButton *refreshTimeButton;
    QLabel *label_2;
    QLineEdit *userWeightInput;
    QPushButton *pushButton;
    QVBoxLayout *calendarLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_13;
    QLabel *selectedFoodNameLabel;
    QLineEdit *selectedFoodWeightInput;
    QSpacerItem *horizontalSpacer;
    QPushButton *consumeFoodButton;

    void setupUi(QWidget *DailyNutrition)
    {
        if (DailyNutrition->objectName().isEmpty())
            DailyNutrition->setObjectName(QString::fromUtf8("DailyNutrition"));
        DailyNutrition->resize(829, 153);
        verticalLayout = new QVBoxLayout(DailyNutrition);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DailyNutrition);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        dateLabel = new QLabel(DailyNutrition);
        dateLabel->setObjectName(QString::fromUtf8("dateLabel"));

        horizontalLayout->addWidget(dateLabel);

        showCalendarButton = new QPushButton(DailyNutrition);
        showCalendarButton->setObjectName(QString::fromUtf8("showCalendarButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pics/choise_button_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        showCalendarButton->setIcon(icon);

        horizontalLayout->addWidget(showCalendarButton);

        refreshDateButton = new QPushButton(DailyNutrition);
        refreshDateButton->setObjectName(QString::fromUtf8("refreshDateButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/pics/refresh_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        refreshDateButton->setIcon(icon1);

        horizontalLayout->addWidget(refreshDateButton);

        label_11 = new QLabel(DailyNutrition);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_11);

        hoursComboBox = new QComboBox(DailyNutrition);
        hoursComboBox->setObjectName(QString::fromUtf8("hoursComboBox"));
        hoursComboBox->setMaxVisibleItems(24);

        horizontalLayout->addWidget(hoursComboBox);

        selectedTimeLabel = new QLabel(DailyNutrition);
        selectedTimeLabel->setObjectName(QString::fromUtf8("selectedTimeLabel"));

        horizontalLayout->addWidget(selectedTimeLabel);

        minutesComboBox = new QComboBox(DailyNutrition);
        minutesComboBox->setObjectName(QString::fromUtf8("minutesComboBox"));
        minutesComboBox->setMaxVisibleItems(12);

        horizontalLayout->addWidget(minutesComboBox);

        refreshTimeButton = new QPushButton(DailyNutrition);
        refreshTimeButton->setObjectName(QString::fromUtf8("refreshTimeButton"));
        refreshTimeButton->setIcon(icon1);

        horizontalLayout->addWidget(refreshTimeButton);

        label_2 = new QLabel(DailyNutrition);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        userWeightInput = new QLineEdit(DailyNutrition);
        userWeightInput->setObjectName(QString::fromUtf8("userWeightInput"));
        userWeightInput->setMaxLength(5);
        userWeightInput->setFrame(true);
        userWeightInput->setClearButtonEnabled(false);

        horizontalLayout->addWidget(userWeightInput);

        pushButton = new QPushButton(DailyNutrition);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(9, 1);
        horizontalLayout->setStretch(10, 1);
        horizontalLayout->setStretch(11, 1);

        verticalLayout->addLayout(horizontalLayout);

        calendarLayout = new QVBoxLayout();
        calendarLayout->setObjectName(QString::fromUtf8("calendarLayout"));

        verticalLayout->addLayout(calendarLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_13 = new QLabel(DailyNutrition);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(label_13);

        selectedFoodNameLabel = new QLabel(DailyNutrition);
        selectedFoodNameLabel->setObjectName(QString::fromUtf8("selectedFoodNameLabel"));
        selectedFoodNameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(selectedFoodNameLabel);

        selectedFoodWeightInput = new QLineEdit(DailyNutrition);
        selectedFoodWeightInput->setObjectName(QString::fromUtf8("selectedFoodWeightInput"));
        selectedFoodWeightInput->setMaxLength(4);

        horizontalLayout_3->addWidget(selectedFoodWeightInput);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        consumeFoodButton = new QPushButton(DailyNutrition);
        consumeFoodButton->setObjectName(QString::fromUtf8("consumeFoodButton"));
        sizePolicy.setHeightForWidth(consumeFoodButton->sizePolicy().hasHeightForWidth());
        consumeFoodButton->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(consumeFoodButton);

        horizontalLayout_3->setStretch(1, 4);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(DailyNutrition);

        QMetaObject::connectSlotsByName(DailyNutrition);
    } // setupUi

    void retranslateUi(QWidget *DailyNutrition)
    {
        DailyNutrition->setWindowTitle(QApplication::translate("DailyNutrition", "Form", nullptr));
        label->setText(QApplication::translate("DailyNutrition", "\320\224\320\260\321\202\320\260", nullptr));
        dateLabel->setText(QApplication::translate("DailyNutrition", "dd.mm.yyyy", nullptr));
        showCalendarButton->setText(QString());
        refreshDateButton->setText(QString());
        label_11->setText(QApplication::translate("DailyNutrition", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        selectedTimeLabel->setText(QApplication::translate("DailyNutrition", ":", nullptr));
        refreshTimeButton->setText(QString());
        label_2->setText(QApplication::translate("DailyNutrition", "\320\234\320\260\321\201\321\201\320\260 \321\202\320\265\320\273\320\260", nullptr));
        userWeightInput->setPlaceholderText(QApplication::translate("DailyNutrition", "\320\272\320\263", nullptr));
        pushButton->setText(QApplication::translate("DailyNutrition", "OK", nullptr));
        label_13->setText(QApplication::translate("DailyNutrition", "\320\241\321\212\320\265\321\201\321\202\321\214: ", nullptr));
        selectedFoodNameLabel->setText(QApplication::translate("DailyNutrition", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\265\320\264\321\213", nullptr));
        selectedFoodWeightInput->setPlaceholderText(QApplication::translate("DailyNutrition", "\320\274\320\260\321\201\321\201\320\260, \320\263", nullptr));
        consumeFoodButton->setText(QApplication::translate("DailyNutrition", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DailyNutrition: public Ui_DailyNutrition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAILYNUTRITION_H
