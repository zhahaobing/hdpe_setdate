#include    <QMessageBox>

#include    "mainwindow.h"
#include    "ui_mainwindow.h"

QString     g_szSetdataFilepath = "";    //定制单文件绝对路径
QMap<QString, SETITEM> g_mapSetItem;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize( QSize( 1200, 750 ));

    pHandleDocx = new pthread_readdoc();

    QStringList sListHeader;
    sListHeader<< tr("地址") << tr("参数设置") << tr("定值设置");
    ui->tableWidget->setColumnCount(sListHeader.size());
    ui->tableWidget->setRowCount(10000000);

    ui->tableWidget->setHorizontalHeaderLabels(sListHeader);
    //ui->tableWidget->setItemDelegate(&settings_combox);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{ //绘制窗口背景图片
    //return;
    Q_UNUSED(event);

}

void MainWindow::on_actionopenfile_triggered()
{
    QString curPath=QDir::currentPath();
    //调用打开文件对话框选择一个文件
    QString aFileName;
    QString szWarnInfo;

    g_szSetdataFilepath.clear();

    aFileName = QFileDialog::getOpenFileName(this,tr("打开一个定制单word文档"),curPath, \
                                                        "WORD文件(*.doc;*.docx)");

    if (aFileName.isEmpty())
    {
        szWarnInfo = tr("定制单文件路径不存在！");
        //printfText(szWarnInfo,2);
        QMessageBox::warning(this, "warning", szWarnInfo, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }
    g_szSetdataFilepath = aFileName;

    //线程开始之前清除一下缓存
    g_mapSetItem.clear();

    pHandleDocx->start();
}

