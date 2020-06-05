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
#endif // MAINWINDOW_H
