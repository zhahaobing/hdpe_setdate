#include    <QMessageBox>

#include    "mainwindow.h"
#include    "ui_mainwindow.h"

QString     g_szSetdataFilepath;    //定制单文件绝对路径

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    aFileName = QFileDialog::getOpenFileName(this,tr("打开一个定制单word文档"),curPath,
                                                        "WORD文件(*.doc;*.docx)");

    if (aFileName.isEmpty())
    {
        szWarnInfo = tr("定制单文件路径不存在！");
        //printfText(szWarnInfo,2);
        QMessageBox::warning(this, "warning", szWarnInfo, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }
    g_szSetdataFilepath = aFileName;
}

