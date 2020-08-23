#ifndef BASIC_INFO_H
#define BASIC_INFO_H

#include <QMainWindow>

namespace Ui {
class BASIC_INFO;
}

//基本信息类
class BASIC_INFO : public QMainWindow
{
    Q_OBJECT

public:
    explicit BASIC_INFO(QWidget *parent = nullptr);
    ~BASIC_INFO();

private:
    Ui::BASIC_INFO *ui;
};

#endif // BASIC_INFO_H
