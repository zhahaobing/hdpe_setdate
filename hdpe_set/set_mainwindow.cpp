#include "set_mainwindow.h"
#include "ui_set_mainwindow.h"

SET_MAINWINDOW::SET_MAINWINDOW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SET_MAINWINDOW)
{
    ui->setupUi(this);

    widget_basic       	= nullptr;//基本信息

    basic_infoTable 	= nullptr;

}

SET_MAINWINDOW::~SET_MAINWINDOW()
{
    if(nullptr != basic_infoTable)
    {
        delete	basic_infoTable;
    }


    delete ui;
}

void SET_MAINWINDOW::on_action_openfile_triggered()
{
    if(widget_basic == nullptr)
    {
        if(nullptr == basic_infoTable)
        {
            basic_infoTable = new BASIC_INFO(this);
        }
        //basic_infoTable->setStyleSheet("background-color:rgb(255, 255, 180);");
        basic_infoTable->setAttribute(Qt::WA_DeleteOnClose); //关闭时自动删除
        basic_infoTable->setProperty("id",0);
        //	  aTable->setWindowTitle("基于QWidget的窗口，无父窗口，关闭时删除");
        ui->tabWidget->addTab(basic_infoTable,tr("基本信息"));
        ui->tabWidget->setCurrentWidget(basic_infoTable);
        ui->tabWidget->setVisible(true);
        //g_nInited_set = ui->tabWidget->count();

        connect(this, SIGNAL(SetMain_SendSignalTo_BasicInfo(int, QString)),basic_infoTable,SLOT(BasicInfoRecvFromSetMain(int, QString)));
    }
    else
    {
        ui->tabWidget->setCurrentWidget(widget_basic);
        ui->tabWidget->setVisible(true);
    }

}
