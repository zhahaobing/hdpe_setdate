#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include    <QMainWindow>
#include    <QFileDialog>
#include    "qformtable_file.h"
#include    "pthread_readdoc.h"

#define     OPENFILE_MAX    16          //最大支持同时打开16个文件

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

private:
    Ui::MainWindow *ui;
    pthread_readdoc *pHandleDocx[OPENFILE_MAX];
    QFormTable_File *formTable_file[OPENFILE_MAX];
    void    paintEvent(QPaintEvent *event);
    int     searchMinIndex();

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

#endif // MAINWINDOW_H
