#include    <QDebug>
#include    <QMessageBox>
#include    <QDebug>
#include    <QStandardItemModel>
#include    "qformtable_file.h"
#include    "ui_qformtable_file.h"
#include    "mainwindow.h"

#define     OPENFILE_MAX    16          //最大支持同时打开16个文件

extern QString  g_szSetdataFilepath[OPENFILE_MAX];        //定制单文档名,带绝对路径
extern QMap<QString, SETITEM> g_mapSetItem[OPENFILE_MAX];

QFormTable_File::QFormTable_File(QWidget *parent, int nIndex) :
    QMainWindow(parent),
    ui(new Ui::QFormTable_File)
{
    ui->setupUi(this);
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    theModel = new QStandardItemModel(12,6,this); //数据模型
    theSelection = new QItemSelectionModel(theModel);//Item选择模型
    g_nIndex = nIndex;
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
    curIndex = szProgress.size();
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

    qDebug() << szSetdataFileTmp << ",at line " << __LINE__ << ",--" << g_nIndex;

    szWarnInfo = tr("当前定值单文件:");
    szWarnInfo += szSetdataFileTmp;
    ui->label->setText(szWarnInfo);

    //ntimer = new QTimer(this);
//    connect(ntimer, SIGNAL(timeout()), this, SLOT(scrollCaption()));
    ntimer->start(250);
    qDebug() <<"zhahaobing"<<endl;

    //文件成功打开，发送信号给主窗口
    emit sendMsgToMain(szSetdataFileTmp, g_nIndex);


}

void QFormTable_File::FormTableRecvFromMain(QString msg, int flag)
{
    if(flag != g_nIndex)
    {//不是发给俺的信号，俺无需理睬啦
        return;
    }

    //这里把g_mapSetItem的内容显示出来
    display_setdata(flag);

    disconnect(ntimer, SIGNAL(timeout()), this, SLOT(scrollCaption()));
    QString szWarnInfo = tr("加载进度:100%");
    ui->label_2->setText(szWarnInfo);

    QMessageBox::information( this, tr("提示"), msg, tr("NO"), tr("YES"), 0, 1 );
    return;
}

void QFormTable_File::display_setdata(int nIndex)
{
    //g_mapSetItem;

    int i = 0;
    QMap<QString, SETITEM>::const_iterator iter_column;
    for(iter_column=g_mapSetItem[nIndex].constBegin(); iter_column != g_mapSetItem[nIndex].constEnd(); iter_column++)
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
    ui->label_2->setText(szProgress.mid(curIndex--));
#endif
}
