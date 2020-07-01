#include    <QPainter>
#include    <QFileDialog>
#include    <QMessageBox>
#include    <QDebug>
#include    <QTime>
#include    <QTimer>
#include    "mainwindow.h"
#include    "ui_mainwindow.h"

QString     g_szSetdataFilepath;      //定制单文件绝对路径
BASICITEM   g_FileBasicInfo;          //定值单文件基本信息
QMap<QString, SETITEM> g_mapSetItem;
int         g_nFileIndexPool;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //this->resize( QSize( 1800, 1200 ));

    //这里初始化类成员变量
    picFileIndex = 0;
    tabWidgetList.clear();
    formTable_file = nullptr;

    ui->tabWidget->setVisible(false);
    ui->tabWidget->clear();//清除所有页面
    ui->tabWidget->tabsClosable(); //Page有关闭按钮，可被关闭

    this->setCentralWidget(ui->tabWidget);
    //this->setWindowState(Qt::WindowFullScreen); //窗口最大化显示
    //this->setWindowState(Qt::WindowMaximized); //窗口最大化显示
//    this->setWindowState(Qt::WindowMinimized); //窗口最大化显示
    this->setAutoFillBackground(true);

    g_nFileIndexPool = 0;

    connect(ui->tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(removeSubTab(int)));
}

MainWindow::~MainWindow()
{
    if(nullptr != formTable_file)
    {
        delete formTable_file;
    }
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{ //绘制窗口背景图片
    Q_UNUSED(event);
    QPainter painter(this);
    if(picFileIndex <= 0)
    {
        qsrand(time(nullptr));
        picFileIndex = (qrand() % 20) + 1;    //产生1-20的随机数
        //qDebug() << "picFileIndex:" << picFileIndex << "at line " << __LINE__;
    }
    QString picFile = ":/images/images/";
    picFile += QString::asprintf("back%02d.jpg", picFileIndex);

    //this->height()-ui->toolBar->height()-ui->statusbar->height()
    painter.drawPixmap(0,ui->toolBar->height(),this->width(),
                       this->height()-ui->toolBar->height()-ui->statusbar->height(),
                       QPixmap(picFile));
}

/******************************************************************************
 * on_action_file_triggered
 * 功能:文件操作，从定制单文件中初始化显示的定制单内容
 * 参数:
 * 返回值:
 *****************************************************************************/
void MainWindow::on_action_file_triggered()
{
    QString szWarnInfo;

    if(nullptr != formTable_file)
    {
        ui->tabWidget->setVisible(true);
        qDebug() << ",file:" << __FILE__ << ",at line:" << __LINE__;
        return;
    }

    formTable_file = new QFormTable_File(this);


//    if(i >= 16)
//    {
//        szWarnInfo = tr("最多只允许同时打开16个定值单文件窗口！");
//        QMessageBox::warning(this, "warning", szWarnInfo, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
//        return;
//    }

    //绑定信号和槽函数
    connect(formTable_file, SIGNAL(sendMsgToMain(QString, int)),this,SLOT(recvFromFormTable(QString, int)));
    connect(this, SIGNAL(MainSendMsgToFormTable(QString, int)),formTable_file,SLOT(FormTableRecvFromMain(QString, int)));

    formTable_file->setAttribute(Qt::WA_DeleteOnClose); //关闭时自动删除
    //    aTable->setWindowTitle("基于QWidget的窗口，无父窗口，关闭时删除");
    QString szFile = tr("定值单文件");
    int cur=ui->tabWidget->addTab(formTable_file,
              szFile);
    ui->tabWidget->setCurrentIndex(cur);
    ui->tabWidget->setVisible(true);
    tabWidgetList.append("formTable_file");
}

void MainWindow::recvFromFormTable(QString msg, int flag)
{
    QString szWarnInfo;
    qDebug() << "file:" << __FILE__ << ",at line " << __LINE__;

    switch(flag)
    {
        case 0:
        {//文件已经打开，接下来需要进行解析
            g_szSetdataFilepath = msg;
//            if(nullptr != pHandleDocx)
//            {
//                delete pHandleDocx;
//                pHandleDocx = nullptr;
//            }
            qDebug() << g_szSetdataFilepath << ",file:" << __FILE__ << ",at line " << __LINE__;

            pHandleDocx = new pthread_readdoc();
            connect(pHandleDocx, SIGNAL(ReaddocSendMsgToMain(QString, int)),this,SLOT(recvFromThreaddoc(QString, int)));
            pHandleDocx->start();

            break;
        }
        case 1:
        {
            break;
        }
        default:
        {
            break;
        }
    }

}

void MainWindow::recvFromThreaddoc(QString msg, int flag)
{
//    QString szWarnInfo;
//    if(flag > 16 || flag < 0)
//    {
//        szWarnInfo = tr("来自错误定值单窗口的信号！");
//        QMessageBox::warning(this, "warning", szWarnInfo, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

//        return;
//    }

    switch(flag)
    {
        case 0:
        {
            emit MainSendMsgToFormTable(msg, flag);

            break;
        }
        case 1:
        {
            emit MainSendMsgToFormTable(msg, flag);
            break;
        }
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        {
            emit MainSendMsgToFormTable(msg, flag);
            break;
        }
        case 13:
        {//装置版本号
            emit MainSendMsgToFormTable(msg, flag);
            break;
        }
        default:
        {
            emit MainSendMsgToFormTable(msg, flag);
            break;
        }
    }
}

//帮助按钮
void MainWindow::on_action_help_triggered()
{
    QString szHelp = tr("帮助");
    QString szInfo = tr("开发人员");
    szInfo += ":zhahaobing@126.com";
    szInfo += "<br>";
    szInfo += tr("版本");
    szInfo += ":0.2.0.0";
    szInfo += "<br>";
    szInfo += tr("日期");
    szInfo += ":2020-06-14";

    QMessageBox::about(this, szHelp, "<font color='red'>" + szInfo +"</font>");
}

void MainWindow::removeSubTab(int index)
{
    qDebug() << "index=" << index << ",file:" << __FILE__ << ",at line:" << __LINE__;

    QWidget *pItemWidget = ui->tabWidget->widget(index);
    pItemWidget->close();
    QString tabName = QString::asprintf("tab%02d", index);

    if(tabWidgetList[index] == QString::fromLocal8Bit("formTable_file"))
    {
        delete formTable_file;
        formTable_file = nullptr;
    }
    tabWidgetList.removeAt(index);

    if(nullptr == formTable_file)
    {
        ui->tabWidget->setVisible(false);
        ui->tabWidget->clear();//清除所有页面
        tabWidgetList.clear();

    }
}
