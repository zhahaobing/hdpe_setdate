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
#include <QtWidgets/QLineEdit>
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
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_18;
    QLabel *label_20;
    QLabel *label_19;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_22;
    QLabel *label_17;
    QLabel *label_21;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *lineEdit__organization;
    QLineEdit *lineEdit_DeviceID;
    QLineEdit *lineEdit_DeviceName;
    QLineEdit *lineEdit_DeviceType;
    QLineEdit *lineEdit_DeadLine;
    QLineEdit *lineEdit_DeviceVersionNo;
    QLineEdit *lineEdit_DeviceSQE;
    QLineEdit *lineEdit_DeviceIEDAddr;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_PortB_IP;
    QLineEdit *lineEdit_PortB_NetMask;
    QLineEdit *lineEdit_PortB_Gateway;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_PortC_IP;
    QLineEdit *lineEdit_PortC_NetMask;
    QLineEdit *lineEdit_PortC_Gateway;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *QFormTable_File)
    {
        if (QFormTable_File->objectName().isEmpty())
            QFormTable_File->setObjectName(QString::fromUtf8("QFormTable_File"));
        QFormTable_File->resize(535, 605);
        action_open = new QAction(QFormTable_File);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/122.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon);
        centralwidget = new QWidget(QFormTable_File);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(groupBox_2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        groupBox = new QGroupBox(groupBox_2);
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
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\232\266\344\271\246\";"));

        horizontalLayout->addWidget(label);


        verticalLayout->addWidget(groupBox);


        horizontalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\232\266\344\271\246\";\n"
"background-color: rgb(170, 170, 127);"));
        verticalLayout_8 = new QVBoxLayout(groupBox_3);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        groupBox_6 = new QGroupBox(groupBox_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_18 = new QLabel(groupBox_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_6->addWidget(label_18);

        label_20 = new QLabel(groupBox_6);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_6->addWidget(label_20);

        label_19 = new QLabel(groupBox_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_6->addWidget(label_19);

        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        verticalLayout_6->addWidget(label_23);

        label_24 = new QLabel(groupBox_6);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout_6->addWidget(label_24);

        label_22 = new QLabel(groupBox_6);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        verticalLayout_6->addWidget(label_22);

        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_6->addWidget(label_17);

        label_21 = new QLabel(groupBox_6);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_6->addWidget(label_21);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        lineEdit__organization = new QLineEdit(groupBox_6);
        lineEdit__organization->setObjectName(QString::fromUtf8("lineEdit__organization"));

        verticalLayout_7->addWidget(lineEdit__organization);

        lineEdit_DeviceID = new QLineEdit(groupBox_6);
        lineEdit_DeviceID->setObjectName(QString::fromUtf8("lineEdit_DeviceID"));

        verticalLayout_7->addWidget(lineEdit_DeviceID);

        lineEdit_DeviceName = new QLineEdit(groupBox_6);
        lineEdit_DeviceName->setObjectName(QString::fromUtf8("lineEdit_DeviceName"));

        verticalLayout_7->addWidget(lineEdit_DeviceName);

        lineEdit_DeviceType = new QLineEdit(groupBox_6);
        lineEdit_DeviceType->setObjectName(QString::fromUtf8("lineEdit_DeviceType"));

        verticalLayout_7->addWidget(lineEdit_DeviceType);

        lineEdit_DeadLine = new QLineEdit(groupBox_6);
        lineEdit_DeadLine->setObjectName(QString::fromUtf8("lineEdit_DeadLine"));

        verticalLayout_7->addWidget(lineEdit_DeadLine);

        lineEdit_DeviceVersionNo = new QLineEdit(groupBox_6);
        lineEdit_DeviceVersionNo->setObjectName(QString::fromUtf8("lineEdit_DeviceVersionNo"));

        verticalLayout_7->addWidget(lineEdit_DeviceVersionNo);

        lineEdit_DeviceSQE = new QLineEdit(groupBox_6);
        lineEdit_DeviceSQE->setObjectName(QString::fromUtf8("lineEdit_DeviceSQE"));

        verticalLayout_7->addWidget(lineEdit_DeviceSQE);

        lineEdit_DeviceIEDAddr = new QLineEdit(groupBox_6);
        lineEdit_DeviceIEDAddr->setObjectName(QString::fromUtf8("lineEdit_DeviceIEDAddr"));

        verticalLayout_7->addWidget(lineEdit_DeviceIEDAddr);


        horizontalLayout_4->addLayout(verticalLayout_7);


        verticalLayout_8->addWidget(groupBox_6);

        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_2->addWidget(label_13);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_2->addWidget(label_11);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_2->addWidget(label_12);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lineEdit_PortB_IP = new QLineEdit(groupBox_4);
        lineEdit_PortB_IP->setObjectName(QString::fromUtf8("lineEdit_PortB_IP"));

        verticalLayout_3->addWidget(lineEdit_PortB_IP);

        lineEdit_PortB_NetMask = new QLineEdit(groupBox_4);
        lineEdit_PortB_NetMask->setObjectName(QString::fromUtf8("lineEdit_PortB_NetMask"));

        verticalLayout_3->addWidget(lineEdit_PortB_NetMask);

        lineEdit_PortB_Gateway = new QLineEdit(groupBox_4);
        lineEdit_PortB_Gateway->setObjectName(QString::fromUtf8("lineEdit_PortB_Gateway"));

        verticalLayout_3->addWidget(lineEdit_PortB_Gateway);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_8->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_4->addWidget(label_14);

        label_15 = new QLabel(groupBox_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_4->addWidget(label_15);

        label_16 = new QLabel(groupBox_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_4->addWidget(label_16);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lineEdit_PortC_IP = new QLineEdit(groupBox_5);
        lineEdit_PortC_IP->setObjectName(QString::fromUtf8("lineEdit_PortC_IP"));

        verticalLayout_5->addWidget(lineEdit_PortC_IP);

        lineEdit_PortC_NetMask = new QLineEdit(groupBox_5);
        lineEdit_PortC_NetMask->setObjectName(QString::fromUtf8("lineEdit_PortC_NetMask"));

        verticalLayout_5->addWidget(lineEdit_PortC_NetMask);

        lineEdit_PortC_Gateway = new QLineEdit(groupBox_5);
        lineEdit_PortC_Gateway->setObjectName(QString::fromUtf8("lineEdit_PortC_Gateway"));

        verticalLayout_5->addWidget(lineEdit_PortC_Gateway);


        horizontalLayout_3->addLayout(verticalLayout_5);


        verticalLayout_8->addWidget(groupBox_5);


        horizontalLayout_5->addWidget(groupBox_3);

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
        groupBox_2->setTitle(QString());
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("QFormTable_File", "\345\212\240\350\275\275\350\277\233\345\272\246:", nullptr));
        label->setText(QCoreApplication::translate("QFormTable_File", "\345\275\223\345\211\215\345\256\232\345\200\274\345\215\225\346\226\207\344\273\266:", nullptr));
        groupBox_3->setTitle(QString());
        groupBox_6->setTitle(QString());
        label_18->setText(QCoreApplication::translate("QFormTable_File", "\345\217\227\344\273\244\345\215\225\344\275\215\357\274\232", nullptr));
        label_20->setText(QCoreApplication::translate("QFormTable_File", "\350\256\276\345\244\207\344\275\215\345\217\267:", nullptr));
        label_19->setText(QCoreApplication::translate("QFormTable_File", "\350\256\276\345\244\207\345\220\215\347\247\260:", nullptr));
        label_23->setText(QCoreApplication::translate("QFormTable_File", "\350\243\205\347\275\256\345\236\213\345\217\267\357\274\232", nullptr));
        label_24->setText(QCoreApplication::translate("QFormTable_File", "\346\233\264\346\224\271\346\234\237\351\231\220\357\274\232", nullptr));
        label_22->setText(QCoreApplication::translate("QFormTable_File", "\350\243\205\347\275\256\347\211\210\346\234\254\345\217\267:", nullptr));
        label_17->setText(QCoreApplication::translate("QFormTable_File", "\350\243\205\347\275\256\345\272\217\345\210\227\345\217\267:", nullptr));
        label_21->setText(QCoreApplication::translate("QFormTable_File", "\350\243\205\347\275\256IED\345\234\260\345\235\200:", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("QFormTable_File", "\347\253\257\345\217\243B", nullptr));
        label_13->setText(QCoreApplication::translate("QFormTable_File", "IP\345\234\260\345\235\200:", nullptr));
        label_11->setText(QCoreApplication::translate("QFormTable_File", "\345\255\220\347\275\221\346\216\251\347\240\201:", nullptr));
        label_12->setText(QCoreApplication::translate("QFormTable_File", "\351\273\230\350\256\244\347\275\221\345\205\263:", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("QFormTable_File", "\347\253\257\345\217\243C", nullptr));
        label_14->setText(QCoreApplication::translate("QFormTable_File", "IP\345\234\260\345\235\200:", nullptr));
        label_15->setText(QCoreApplication::translate("QFormTable_File", "\345\255\220\347\275\221\346\216\251\347\240\201:", nullptr));
        label_16->setText(QCoreApplication::translate("QFormTable_File", "\351\273\230\350\256\244\347\275\221\345\205\263:", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("QFormTable_File", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QFormTable_File: public Ui_QFormTable_File {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFORMTABLE_FILE_H
