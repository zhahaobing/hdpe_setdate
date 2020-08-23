#ifndef SET_MAINWINDOW_H
#define SET_MAINWINDOW_H

#include <QMainWindow>
#include "basic_info.h"

namespace Ui {
class SET_MAINWINDOW;
}

class SET_MAINWINDOW : public QMainWindow
{
    Q_OBJECT

public:
    explicit SET_MAINWINDOW(QWidget *parent = nullptr);
    ~SET_MAINWINDOW();

private slots:
    void on_action_openfile_triggered();

private:
    Ui::SET_MAINWINDOW *ui;
    QWidget     				*widget_basic;              //基本信息

    BASIC_INFO 					*basic_infoTable;

};

#endif // SET_MAINWINDOW_H
