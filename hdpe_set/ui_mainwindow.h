/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_file;
    QAction *action_database;
    QAction *action_log;
    QAction *action_help;
    QAction *action_exit;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        action_file = new QAction(MainWindow);
        action_file->setObjectName(QString::fromUtf8("action_file"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/school_work_icon_homework_128px_25925_easyicon.net.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_file->setIcon(icon);
        action_database = new QAction(MainWindow);
        action_database->setObjectName(QString::fromUtf8("action_database"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/Excel.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_database->setIcon(icon1);
        action_log = new QAction(MainWindow);
        action_log->setObjectName(QString::fromUtf8("action_log"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/100.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_log->setIcon(icon2);
        action_help = new QAction(MainWindow);
        action_help->setObjectName(QString::fromUtf8("action_help"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/about.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_help->setIcon(icon3);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/power_off.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon4);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(70, 80, 261, 191));
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(action_file);
        toolBar->addSeparator();
        toolBar->addAction(action_database);
        toolBar->addSeparator();
        toolBar->addAction(action_log);
        toolBar->addSeparator();
        toolBar->addAction(action_help);
        toolBar->addSeparator();
        toolBar->addAction(action_exit);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_file->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(tooltip)
        action_file->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\346\223\215\344\275\234", nullptr));
#endif // QT_CONFIG(tooltip)
        action_database->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223", nullptr));
#if QT_CONFIG(tooltip)
        action_database->setToolTip(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\346\223\215\344\275\234", nullptr));
#endif // QT_CONFIG(tooltip)
        action_log->setText(QCoreApplication::translate("MainWindow", "\346\227\245\345\277\227", nullptr));
#if QT_CONFIG(tooltip)
        action_log->setToolTip(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\346\227\245\345\277\227\344\277\241\346\201\257", nullptr));
#endif // QT_CONFIG(tooltip)
        action_help->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#if QT_CONFIG(tooltip)
        action_help->setToolTip(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
#endif // QT_CONFIG(tooltip)
        action_exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        action_exit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\346\234\254\350\275\257\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
