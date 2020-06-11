#ifndef LOG_WINDOWS_H
#define LOG_WINDOWS_H

#include <QDialog>

namespace Ui {
class Log_Windows;
}

class Log_Windows : public QDialog
{
    Q_OBJECT

public:
    explicit Log_Windows(QWidget *parent = nullptr);
    ~Log_Windows();

private:
    Ui::Log_Windows *ui;
};

#endif // LOG_WINDOWS_H
