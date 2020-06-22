#include    <QPainter>
#include    <QFileDialog>
#include    <QMessageBox>
#include    <qDebug>
#include    "mainwindow.h"
#include    "ui_mainwindow.h"

QString     g_szSetdataFilepath[OPENFILE_MAX] = {""};      //定制单文件绝对路径
QMap<QString, SETITEM> g_mapSetItem[OPENFILE_MAX];
int         g_nFileIndexPool[OPENFILE_MAX] = {0};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    this->resize( QSize( 1200, 750 ));

    ui->tabWidget->setVisible(false);
    ui->tabWidget->clear();//清除所有页面
    ui->tabWidget->tabsClosable(); //Page有关闭按钮，可被关闭

    this->setCentralWidget(ui->tabWidget);
//    this->setWindowState(Qt::WindowFullScreen); //窗口最大化显示
    //this->setWindowState(Qt::WindowMaximized); //窗口最大化显示
//    this->setWindowState(Qt::WindowMinimized); //窗口最大化显示
    this->setAutoFillBackground(true);

    int i = 0;
    for(i=0; i< OPENFILE_MAX; i++)
    {
        g_nFileIndexPool[i] = 0;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{ //绘制窗口背景图片
    Q_UNUSED(event);
    QPainter painter(this);

    //this->height()-ui->toolBar->height()-ui->statusbar->height()
    painter.drawPixmap(0,ui->toolBar->height(),this->width(),
                       this->height()-ui->toolBar->height()-ui->statusbar->height(),
                       QPixmap(":/images/images/back01.jpg"));
}

/******************************************************************************
 * on_action_file_triggered
 * 功能:文件操作，从定制单文件中初始化显示的定制单内容
 * 参数:
 * 返回值:
 *****************************************************************************/
void MainWindow::on_action_file_triggered()
{
    int i = 0;
    QString szWarnInfo;
    i = searchMinIndex();

    if(i >= 16)
    {
        szWarnInfo = tr("最多只允许同时打开16个定值单文件窗口！");
        QMessageBox::warning(this, "warning", szWarnInfo, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }

    g_nFileIndexPool[i] = 1;
    formTable_file[i] = new QFormTable_File(this, i);

    //绑定信号和槽函数
    connect(formTable_file[i], SIGNAL(sendMsgToMain(QString, int)),this,SLOT(recvFromFormTable(QString, int)));
    connect(this, SIGNAL(MainSendMsgToFormTable(QString, int)),formTable_file[i],SLOT(FormTableRecvFromMain(QString, int)));

    formTable_file[i]->setAttribute(Qt::WA_DeleteOnClose); //关闭时自动删除
    //    aTable->setWindowTitle("基于QWidget的窗口，无父窗口，关闭时删除");
    QString szFile = tr("定值单文件");
    int cur=ui->tabWidget->addTab(formTable_file[i],
              szFile + QString::asprintf(" %d",i + 1));
    ui->tabWidget->setCurrentIndex(cur);
    ui->tabWidget->setVisible(true);

}

//寻找最小的未用的index
int MainWindow::searchMinIndex()
{
    int i = 0;
    for(i=0; i< OPENFILE_MAX; i++)
    {
        if(g_nFileIndexPool[i] == 0)
        {
            return i;
        }
    }

    return 16;
}

void MainWindow::recvFromFormTable(QString msg, int flag)
{
    QString szWarnInfo;
    if(flag > 16 || flag < 0)
    {
        szWarnInfo = tr("来自错误定值单窗口的信号！");
        QMessageBox::warning(this, "warning", szWarnInfo, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

        return;
    }

    g_szSetdataFilepath[flag] = msg;

    szWarnInfo = tr("来自窗口") + QString::number(flag);
    qDebug() << szWarnInfo;

    pHandleDocx[flag] = new pthread_readdoc(flag);
    connect(pHandleDocx[flag], SIGNAL(ReaddocSendMsgToMain(QString, int)),this,SLOT(recvFromThreaddoc(QString, int)));
    pHandleDocx[flag]->start();
}

void MainWindow::recvFromThreaddoc(QString msg, int flag)
{
    QString szWarnInfo;
    if(flag > 16 || flag < 0)
    {
        szWarnInfo = tr("来自错误定值单窗口的信号！");
        QMessageBox::warning(this, "warning", szWarnInfo, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

        return;
    }
    if(msg == QString::fromLocal8Bit("over"))
    {//线程处理结束了，主窗口发消息给QFormTable
        emit MainSendMsgToFormTable("over", flag);
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
    szInfo += ":0.0.2";
    szInfo += "<br>";
    szInfo += tr("日期");
    szInfo += ":2020-06-14";

    QMessageBox::about(this, szHelp, "<font color='red'>" + szInfo +"</font>");
}
