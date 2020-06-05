#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include    <QMainWindow>
#include    <QFileDialog>
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
    void on_actionopenfile_triggered();

private:
    Ui::MainWindow *ui;
    pthread_readdoc     *pHandleDocx;      //读取定制单文档的子线程

    void paintEvent(QPaintEvent *event);

};

typedef struct _SETITEM
{//定值类型结构体
    QString         set_addr;           //定值地址
    QString         set_name;           //参数设置(参数名、定值名称)
    QString         set_type;           //定值类型
    QString         set_value;          //定值设置
}SETITEM,*PSETITEM;

#endif // MAINWINDOW_H
