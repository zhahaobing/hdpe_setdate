/********************************************************************************
** Form generated from reading UI file 'qformtable_file.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFORMTABLE_FILE_H
#define UI_QFORMTABLE_FILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QFormTable_File
{
public:
    QAction *action_open;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *QFormTable_File)
    {
        if (QFormTable_File->objectName().isEmpty())
            QFormTable_File->setObjectName(QString::fromUtf8("QFormTable_File"));
        QFormTable_File->resize(716, 544);
        action_open = new QAction(QFormTable_File);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/122.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon);
        centralwidget = new QWidget(QFormTable_File);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 16pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(label_2);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);


        verticalLayout_2->addWidget(groupBox);


        verticalLayout_3->addLayout(verticalLayout_2);

        QFormTable_File->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QFormTable_File);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QFormTable_File->setStatusBar(statusbar);
        toolBar = new QToolBar(QFormTable_File);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QFormTable_File->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(action_open);
        toolBar->addSeparator();

        retranslateUi(QFormTable_File);

        QMetaObject::connectSlotsByName(QFormTable_File);
    } // setupUi

    void retranslateUi(QMainWindow *QFormTable_File)
    {
        QFormTable_File->setWindowTitle(QCoreApplication::translate("QFormTable_File", "MainWindow", nullptr));
        action_open->setText(QCoreApplication::translate("QFormTable_File", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        action_open->setToolTip(QCoreApplication::translate("QFormTable_File", "\346\211\223\345\274\200\344\270\200\344\270\252\345\256\232\345\200\274\345\215\225\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("QFormTable_File", "\345\212\240\350\275\275\350\277\233\345\272\246:", nullptr));
        label->setText(QCoreApplication::translate("QFormTable_File", "\345\275\223\345\211\215\345\256\232\345\200\274\345\215\225\346\226\207\344\273\266:", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("QFormTable_File", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QFormTable_File: public Ui_QFormTable_File {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFORMTABLE_FILE_H
