#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include    <QMainWindow>
#include    <QFileDialog>
#include    "qformtable_file.h"
#include    "pthread_readdoc.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_file_triggered();
    void recvFromFormTable(QString msg, int flag);
    void recvFromThreaddoc(QString msg, int flag);

    void on_action_help_triggered();

    void    removeSubTab(int index);

private:
    Ui::MainWindow *ui;
    int     picFileIndex = 0;
    QList<QString>   tabWidgetList;//tab的索引链表

    pthread_readdoc     *pHandleDocx;
    QFormTable_File     *formTable_file;
    void    paintEvent(QPaintEvent *event);

signals:
    void MainSendMsgToFormTable(QString msg, int clo);//主窗口发射信号给子线程1
};

typedef struct _SETITEM
{//定值类型结构体
    QString         set_addr;           //定值地址
    QString         set_name;           //参数设置(参数名、定值名称)
    QString         set_type;           //定值类型
    QString         set_value;          //定值设置
}SETITEM,*PSETITEM;

typedef struct _BASICITEM
{//基本参数结构体
    QString         strOrganization;            //受令单位
    QString         strDeviceID;                //设备位号
    QString         strDeviceName;              //设备（装置）名称
    QString         strDeviceType;              //设备（装置）类型
    QString         strDeadline;                //更改期限
    QString         strDeviceVersion;           //装置版本号
    QString         strDeviceSeqNo;             //装置序列号
    QString         strDeviceIEDAddr;           //装置IED地址

    QString         strPortB_IP;                //端口B ip地址
    QString         strPortB_Netmask;           //端口B 子网掩码
    QString         strPortB_Gateway;           //端口B 默认网关

    QString         strPortC_IP;                //端口C ip地址
    QString         strPortC_Netmask;           //端口C 子网掩码
    QString         strPortC_Gateway;           //端口C 默认网关

}BASICITEM,*PBASICITEM;


#endif // MAINWINDOW_H
