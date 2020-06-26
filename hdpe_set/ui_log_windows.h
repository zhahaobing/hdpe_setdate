/********************************************************************************
** Form generated from reading UI file 'log_windows.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_WINDOWS_H
#define UI_LOG_WINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Log_Windows
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;

    void setupUi(QDialog *Log_Windows)
    {
        if (Log_Windows->objectName().isEmpty())
            Log_Windows->setObjectName(QString::fromUtf8("Log_Windows"));
        Log_Windows->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(Log_Windows);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(Log_Windows);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        horizontalLayout->addLayout(horizontalLayout_3);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        horizontalLayout_4->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(Log_Windows);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(Log_Windows);

        QMetaObject::connectSlotsByName(Log_Windows);
    } // setupUi

    void retranslateUi(QDialog *Log_Windows)
    {
        Log_Windows->setWindowTitle(QCoreApplication::translate("Log_Windows", "Dialog", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Log_Windows", "GroupBox", nullptr));
        pushButton->setText(QCoreApplication::translate("Log_Windows", "\346\220\234\347\264\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Log_Windows", "\344\277\235\345\255\230\346\227\245\345\277\227", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Log_Windows", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Log_Windows: public Ui_Log_Windows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_WINDOWS_H
