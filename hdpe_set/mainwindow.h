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

#endif // MAINWINDOW_H
