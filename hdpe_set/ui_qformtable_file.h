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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
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
    QProgressBar *progressBar;
    QFrame *line;
    QLabel *label;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_Organization;
    QLabel *label_DeviceID;
    QLabel *label_DevName;
    QLabel *label_DevType;
    QLabel *label_MOdifyDeadline;
    QLabel *label_DevVersion;
    QLabel *label_DevSqeNo;
    QLabel *label_DevIEDAddr;
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
    QLabel *label_PortB_IP;
    QLabel *label_PortB_Netmask;
    QLabel *label_PortB_Gateway;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_PortB_IP;
    QLineEdit *lineEdit_PortB_NetMask;
    QLineEdit *lineEdit_PortB_Gateway;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_PortC_IP;
    QLabel *label_PortC_Netmask;
    QLabel *label_PortC_Gateway;
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
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\232\266\344\271\246\";"));
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

        horizontalLayout->addWidget(label_2);

        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);

        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAutoFillBackground(true);
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\232\266\344\271\246\";"));

        horizontalLayout->addWidget(label);


        verticalLayout->addWidget(groupBox);


        horizontalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(180, 550));
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
        label_Organization = new QLabel(groupBox_6);
        label_Organization->setObjectName(QString::fromUtf8("label_Organization"));

        verticalLayout_6->addWidget(label_Organization);

        label_DeviceID = new QLabel(groupBox_6);
        label_DeviceID->setObjectName(QString::fromUtf8("label_DeviceID"));

        verticalLayout_6->addWidget(label_DeviceID);

        label_DevName = new QLabel(groupBox_6);
        label_DevName->setObjectName(QString::fromUtf8("label_DevName"));

        verticalLayout_6->addWidget(label_DevName);

        label_DevType = new QLabel(groupBox_6);
        label_DevType->setObjectName(QString::fromUtf8("label_DevType"));

        verticalLayout_6->addWidget(label_DevType);

        label_MOdifyDeadline = new QLabel(groupBox_6);
        label_MOdifyDeadline->setObjectName(QString::fromUtf8("label_MOdifyDeadline"));

        verticalLayout_6->addWidget(label_MOdifyDeadline);

        label_DevVersion = new QLabel(groupBox_6);
        label_DevVersion->setObjectName(QString::fromUtf8("label_DevVersion"));

        verticalLayout_6->addWidget(label_DevVersion);

        label_DevSqeNo = new QLabel(groupBox_6);
        label_DevSqeNo->setObjectName(QString::fromUtf8("label_DevSqeNo"));

        verticalLayout_6->addWidget(label_DevSqeNo);

        label_DevIEDAddr = new QLabel(groupBox_6);
        label_DevIEDAddr->setObjectName(QString::fromUtf8("label_DevIEDAddr"));

        verticalLayout_6->addWidget(label_DevIEDAddr);


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
        label_PortB_IP = new QLabel(groupBox_4);
        label_PortB_IP->setObjectName(QString::fromUtf8("label_PortB_IP"));

        verticalLayout_2->addWidget(label_PortB_IP);

        label_PortB_Netmask = new QLabel(groupBox_4);
        label_PortB_Netmask->setObjectName(QString::fromUtf8("label_PortB_Netmask"));

        verticalLayout_2->addWidget(label_PortB_Netmask);

        label_PortB_Gateway = new QLabel(groupBox_4);
        label_PortB_Gateway->setObjectName(QString::fromUtf8("label_PortB_Gateway"));

        verticalLayout_2->addWidget(label_PortB_Gateway);


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
        label_PortC_IP = new QLabel(groupBox_5);
        label_PortC_IP->setObjectName(QString::fromUtf8("label_PortC_IP"));

        verticalLayout_4->addWidget(label_PortC_IP);

        label_PortC_Netmask = new QLabel(groupBox_5);
        label_PortC_Netmask->setObjectName(QString::fromUtf8("label_PortC_Netmask"));

        verticalLayout_4->addWidget(label_PortC_Netmask);

        label_PortC_Gateway = new QLabel(groupBox_5);
        label_PortC_Gateway->setObjectName(QString::fromUtf8("label_PortC_Gateway"));

        verticalLayout_4->addWidget(label_PortC_Gateway);


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
        label_2->setText(QCoreApplication::translate("QFormTable_File", "\346\226\207\344\273\266\345\212\240\350\275\275\350\277\233\345\272\246:", nullptr));
        label->setText(QCoreApplication::translate("QFormTable_File", "\345\275\223\345\211\215\345\256\232\345\200\274\345\215\225\346\226\207\344\273\266:                                                   ", nullptr));
        groupBox_3->setTitle(QString());
        groupBox_6->setTitle(QString());
        label_Organization->setText(QCoreApplication::translate("QFormTable_File", "\345\217\227\344\273\244\345\215\225\344\275\215\357\274\232", nullptr));
        label_DeviceID->setText(QCoreApplication::translate("QFormTable_File", "\350\256\276\345\244\207\344\275\215\345\217\267:", nullptr));
        label_DevName->setText(QCoreApplication::translate("QFormTable_File", "\350\256\276\345\244\207\345\220\215\347\247\260:", nullptr));
        label_DevType->setText(QCoreApplication::translate("QFormTable_File", "\350\243\205\347\275\256\345\236\213\345\217\267\357\274\232", nullptr));
        label_MOdifyDeadline->setText(QCoreApplication::translate("QFormTable_File", "\346\233\264\346\224\271\346\234\237\351\231\220\357\274\232", nullptr));
        label_DevVersion->setText(QCoreApplication::translate("QFormTable_File", "\350\243\205\347\275\256\347\211\210\346\234\254\345\217\267:", nullptr));
        label_DevSqeNo->setText(QCoreApplication::translate("QFormTable_File", "\350\243\205\347\275\256\345\272\217\345\210\227\345\217\267:", nullptr));
        label_DevIEDAddr->setText(QCoreApplication::translate("QFormTable_File", "\350\243\205\347\275\256IED\345\234\260\345\235\200:", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("QFormTable_File", "\347\253\257\345\217\243B", nullptr));
        label_PortB_IP->setText(QCoreApplication::translate("QFormTable_File", "IP\345\234\260\345\235\200:", nullptr));
        label_PortB_Netmask->setText(QCoreApplication::translate("QFormTable_File", "\345\255\220\347\275\221\346\216\251\347\240\201:", nullptr));
        label_PortB_Gateway->setText(QCoreApplication::translate("QFormTable_File", "\351\273\230\350\256\244\347\275\221\345\205\263:", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("QFormTable_File", "\347\253\257\345\217\243C", nullptr));
        label_PortC_IP->setText(QCoreApplication::translate("QFormTable_File", "IP\345\234\260\345\235\200:", nullptr));
        label_PortC_Netmask->setText(QCoreApplication::translate("QFormTable_File", "\345\255\220\347\275\221\346\216\251\347\240\201:", nullptr));
        label_PortC_Gateway->setText(QCoreApplication::translate("QFormTable_File", "\351\273\230\350\256\244\347\275\221\345\205\263:", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("QFormTable_File", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QFormTable_File: public Ui_QFormTable_File {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFORMTABLE_FILE_H
