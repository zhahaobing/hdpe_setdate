#include "basic_info.h"
#include "ui_basic_info.h"

BASIC_INFO::BASIC_INFO(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BASIC_INFO)
{
    ui->setupUi(this);
}

BASIC_INFO::~BASIC_INFO()
{
    delete ui;
}
