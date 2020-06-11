#include "log_windows.h"
#include "ui_log_windows.h"

Log_Windows::Log_Windows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Log_Windows)
{
    ui->setupUi(this);
}

Log_Windows::~Log_Windows()
{
    delete ui;
}
