/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QTextEdit *textEdit_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QListView *listView;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 321, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_2->addWidget(textEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        textEdit_2 = new QTextEdit(verticalLayoutWidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        verticalLayout_3->addWidget(textEdit_2);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(370, 0, 321, 221));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_4->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(verticalLayoutWidget_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        pushButton = new QPushButton(verticalLayoutWidget_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_2 = new QPushButton(verticalLayoutWidget_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        checkBox = new QCheckBox(verticalLayoutWidget_4);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_3->addWidget(checkBox);


        verticalLayout_4->addLayout(horizontalLayout_3);

        listView = new QListView(verticalLayoutWidget_4);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setEnabled(true);
        QPalette palette;
        QBrush brush(QColor(240, 240, 240, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        listView->setPalette(palette);
        listView->setFrameShape(QFrame::NoFrame);
        listView->setTabKeyNavigation(false);
        listView->setProperty("showDropIndicator", QVariant(true));
        listView->setDragEnabled(true);
        listView->setDragDropOverwriteMode(false);
        listView->setDragDropMode(QAbstractItemView::DragDrop);
        listView->setDefaultDropAction(Qt::MoveAction);
        listView->setFlow(QListView::TopToBottom);
        listView->setLayoutMode(QListView::SinglePass);
        listView->setViewMode(QListView::ListMode);

        verticalLayout_4->addWidget(listView);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 230, 681, 191));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        pushButton_3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);


        verticalLayout_5->addLayout(horizontalLayout_4);

        tableView = new QTableView(verticalLayoutWidget_2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setAutoFillBackground(false);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setShowGrid(true);
        tableView->horizontalHeader()->setVisible(true);
        tableView->horizontalHeader()->setMinimumSectionSize(35);
        tableView->horizontalHeader()->setDefaultSectionSize(120);

        verticalLayout_5->addWidget(tableView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lesson 2", nullptr));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-style:italic;\">1. \320\241\320\277\320\265\321\206\321\201\320\270\320\274\320\262\320\276\320\273\321\213:</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\221\320\260\320\267\320\276\320\262\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "<i>2. \320\241\320\277\320\270\321\201\320\276\320\272 \321\217\320\267\321\213\320\272\320\276\320\262 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217:</i>", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\217\320\267\321\213\320\272", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "OK", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 \320\270\320\272\320\276\320\275\320\276\320\272", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "<i>3. \320\242\320\260\320\261\320\273\320\270\321\206\320\260</i>", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\321\200\320\260\321\201\320\270\321\202\321\214 \321\217\321\207\320\265\320\271\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
