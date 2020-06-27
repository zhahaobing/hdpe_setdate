#include    <QDebug>
#include    <QMessageBox>
#include    <QDebug>
#include    <QStandardItemModel>
#include    "qformtable_file.h"
#include    "ui_qformtable_file.h"
#include    "mainwindow.h"

extern QString  g_szSetdataFilepath;        //定制单文档名,带绝对路径
extern QMap<QString, SETITEM> g_mapSetItem;

QFormTable_File::QFormTable_File(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QFormTable_File)
{
    ui->setupUi(this);
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    theModel = new QStandardItemModel(12,6,this); //数据模型
    theSelection = new QItemSelectionModel(theModel);//Item选择模型
//    QMessageBox::information(this, "消息", "表格窗口被创建");

    QStringList sListHeader;
    sListHeader<< tr("地址") << tr("参数设置") << tr("定值设置");// << tr("定值单位");
    ui->tableWidget->setColumnCount(sListHeader.size());
    ui->tableWidget->setRowCount(99999);

    ui->tableWidget->setHorizontalHeaderLabels(sListHeader);
    //ui->tableWidget->setItemDelegate(&settings_combox);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ntimer = new QTimer(this);
    connect(ntimer, SIGNAL(timeout()), this, SLOT(scrollCaption()));
    //ntimer->start(250);
    szProgress = tr("加载进度：");

    QString szWarnInfo = tr("当前定值单文件:");
    if(80-szWarnInfo.length() > 0) {
        for(int i=0; i< 80-szWarnInfo.length(); i++)
        {
            szWarnInfo += " ";
        }
    }
    ui->label->setText(szWarnInfo);
    ui->label->setMinimumWidth(500);
    ui->label->setMaximumWidth(500);

    //进度条初始化为10万
    g_lProgressMaxNum   = 100000;
    g_lProgressNum      = 0;
    ui->progressBar->setRange(0, g_lProgressMaxNum);
    //ui->progressBar->setMaximumWidth(500);
    ui->progressBar->setMinimumWidth(500);
}

QFormTable_File::~QFormTable_File()
{
    delete ui;
}

//打开定值单文件
void QFormTable_File::on_action_open_triggered()
{
    qDebug() << "打开定值单文件";
    QString curPath=QDir::currentPath();
    //调用打开文件对话框选择一个文件
    QString aFileName;
    QString szWarnInfo;
    QString szSetdataFileTmp;
    int     i = 0;

    aFileName = QFileDialog::getOpenFileName(this,tr("打开一个定制单word文档"),curPath, \
                                                        "WORD文件(*.doc;*.docx)");

    if (aFileName.isEmpty())
    {
        szWarnInfo = tr("定制单文件路径不存在！");
        //printfText(szWarnInfo,2);
        QMessageBox::warning(this, "warning", szWarnInfo, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }
    szSetdataFileTmp = aFileName;

    qDebug() << szSetdataFileTmp << ",at line " << __LINE__;

    szWarnInfo = tr("当前定值单文件:");
    szWarnInfo += szSetdataFileTmp;
    if(80-szWarnInfo.length() > 0) {
        for(int i=0; i< 80-szWarnInfo.length(); i++)
        {
            szWarnInfo += " ";
        }
    }
    ui->label->setText(szWarnInfo);

    //ntimer = new QTimer(this);
//    connect(ntimer, SIGNAL(timeout()), this, SLOT(scrollCaption()));
    ntimer->start(250);
    qDebug() <<"zhahaobing"<<endl;

    //文件成功打开，发送信号给主窗口
    emit sendMsgToMain(szSetdataFileTmp, 0);
}

void QFormTable_File::FormTableRecvFromMain(QString msg, int flag)
{
    switch(flag)
    {
        case 0:
        {
            //这里把g_mapSetItem的内容显示出来
            display_setdata();

//            disconnect(ntimer, SIGNAL(timeout()), this, SLOT(scrollCaption()));
//            QString szWarnInfo = tr("加载进度:100%");
            ui->progressBar->setValue(g_lProgressMaxNum);

            QMessageBox::information( this, tr("提示"), tr("定值单文件解析结束！"));

            break;
        }
        case 1:
        {
            int nProgress = msg.toInt();
            ui->progressBar->setValue(nProgress);
            qDebug() << "nProgress=" << nProgress << ",file:" << __FILE__ << ",at line:" << __LINE__;
            break;
        }
        default:
        {

            break;
        }
    }

    return;
}

void QFormTable_File::display_setdata()
{
    //g_mapSetItem;

    int i = 0;
    QMap<QString, SETITEM>::const_iterator iter_column;
    for(iter_column=g_mapSetItem.constBegin(); iter_column != g_mapSetItem.constEnd(); iter_column++)
    {
        QTableWidgetItem    *Item_set_addr = new QTableWidgetItem(iter_column.value().set_addr);
        Item_set_addr->setBackground(QBrush(QColor(224, 238, 224,255)));
        Item_set_addr->setFlags(Item_set_addr->flags() & (~Qt::ItemIsEditable));
        ui->tableWidget->setItem(i, 0, Item_set_addr);

        QTableWidgetItem    *Item_set_name = new QTableWidgetItem(iter_column.value().set_name);
        Item_set_name->setBackground(QBrush(QColor(224, 238, 224,255)));
        Item_set_name->setFlags(Item_set_name->flags() & (~Qt::ItemIsEditable));
        ui->tableWidget->setItem(i, 1, Item_set_name);

        QTableWidgetItem    *Item_set_value = new QTableWidgetItem(iter_column.value().set_value);
        //Item_set_value->setBackground(QBrush(QColor(Qt::lightGray)));
        //Item_set_value->setFlags(Item_set_value->flags() & (Qt::ItemIsEditable));
        //Item_set_value->setFlags(Qt::ItemIsEditable);
        ui->tableWidget->setItem(i, 2, Item_set_value);

        i++;
    }
    ui->tableWidget->setRowCount(i);

}

void QFormTable_File::scrollCaption()
{
    int isize = szProgress.size(); // 文字个数

#ifdef RT // 左移
    if (curIndex > isize)
        curIndex = 0;
    //qDebug() << curIndex;
    ui->label_2->setText(szProgress.mid(curIndex++)); // .mid（pos）； 从pos开始截取字符串
#endif

#ifndef RT // 右移
    if (curIndex < 0)
        curIndex = isize;
    //qDebug() << curIndex;
    //ui->label_2->setText(szProgress.mid(curIndex--));
#endif
}

void QFormTable_File::closeEvent( QCloseEvent * event )
{
    //sendMsgToMain("0", g_nIndex);
#if 0
    switch( QMessageBox::information( this, tr("提示"), tr("你真的想退出吗?"), tr("是"), tr("否"), 0, 1 ) )
    {
        case 0:
            event->accept();
            break;
        case 1:
        default:
            event->ignore();
            break;
    }
#endif

}
