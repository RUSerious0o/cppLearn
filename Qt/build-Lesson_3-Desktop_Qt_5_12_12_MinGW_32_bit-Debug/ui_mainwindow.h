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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *openFileAction;
    QAction *saveFileAction;
    QAction *showHelpAction;
    QAction *aboutProgramAction;
    QAction *readOnlyAction;
    QAction *newFileAction;
    QAction *shortcutsPrefsAction;
    QAction *translationChangeAction;
    QAction *changeThemeAction;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *hLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(532, 456);
        openFileAction = new QAction(MainWindow);
        openFileAction->setObjectName(QString::fromUtf8("openFileAction"));
        saveFileAction = new QAction(MainWindow);
        saveFileAction->setObjectName(QString::fromUtf8("saveFileAction"));
        saveFileAction->setEnabled(true);
        showHelpAction = new QAction(MainWindow);
        showHelpAction->setObjectName(QString::fromUtf8("showHelpAction"));
        aboutProgramAction = new QAction(MainWindow);
        aboutProgramAction->setObjectName(QString::fromUtf8("aboutProgramAction"));
        readOnlyAction = new QAction(MainWindow);
        readOnlyAction->setObjectName(QString::fromUtf8("readOnlyAction"));
        newFileAction = new QAction(MainWindow);
        newFileAction->setObjectName(QString::fromUtf8("newFileAction"));
        shortcutsPrefsAction = new QAction(MainWindow);
        shortcutsPrefsAction->setObjectName(QString::fromUtf8("shortcutsPrefsAction"));
        translationChangeAction = new QAction(MainWindow);
        translationChangeAction->setObjectName(QString::fromUtf8("translationChangeAction"));
        changeThemeAction = new QAction(MainWindow);
        changeThemeAction->setObjectName(QString::fromUtf8("changeThemeAction"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        hLayout = new QHBoxLayout();
        hLayout->setObjectName(QString::fromUtf8("hLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        hLayout->addWidget(textEdit);

        hLayout->setStretch(0, 5);

        horizontalLayout->addLayout(hLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 532, 20));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_2->setTearOffEnabled(false);
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setCursor(QCursor(Qt::IBeamCursor));
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(32, 32));
        toolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(newFileAction);
        menu->addAction(openFileAction);
        menu->addAction(readOnlyAction);
        menu->addAction(saveFileAction);
        menu_2->addAction(showHelpAction);
        menu_2->addAction(aboutProgramAction);
        menu_3->addAction(shortcutsPrefsAction);
        menu_3->addAction(translationChangeAction);
        menu_3->addAction(changeThemeAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202\320\276\320\262\321\213\320\271 \321\200\320\265\320\264\320\260\320\272\321\202\320\276\321\200", nullptr));
        openFileAction->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        saveFileAction->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        showHelpAction->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\201\320\277\321\200\320\260\320\262\320\272\321\203", nullptr));
        aboutProgramAction->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        readOnlyAction->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\264\320\273\321\217 \321\207\321\202\320\265\320\275\320\270\321\217", nullptr));
        newFileAction->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271", nullptr));
        newFileAction->setIconText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271", nullptr));
        shortcutsPrefsAction->setText(QApplication::translate("MainWindow", "\320\232\320\273\320\260\320\262\320\270\321\210\320\270 \320\261\321\213\321\201\321\202\321\200\320\276\320\263\320\276 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
        translationChangeAction->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \321\217\320\267\321\213\320\272 \320\270\320\275\321\202\320\265\321\200\321\204\320\265\320\271\321\201\320\260", nullptr));
        changeThemeAction->setText(QApplication::translate("MainWindow", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \321\202\320\265\320\274\321\203", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
