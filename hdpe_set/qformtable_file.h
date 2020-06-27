#ifndef QFORMTABLE_FILE_H
#define QFORMTABLE_FILE_H

#include    <QMainWindow>
#include    <QStandardItemModel>
#include    <QItemSelectionModel>
#include    <QFileDialog>
#include    <QDir>
#include    <QTimer>

namespace Ui {
class QFormTable_File;
}

class QFormTable_File : public QMainWindow
{
    Q_OBJECT

public:
    explicit QFormTable_File(QWidget *parent = nullptr);
    ~QFormTable_File();

private slots:
    void on_action_open_triggered();
    void FormTableRecvFromMain(QString, int);
    void scrollCaption();

private:
    QString             szProgress;
    QTimer              *ntimer;
    QStandardItemModel  *theModel;//数据模型
    QItemSelectionModel *theSelection;//Item选择模型
    int                 curIndex;
    long                g_lProgressMaxNum;
    long                g_lProgressNum;

    Ui::QFormTable_File *ui;
    void display_setdata();
    void closeEvent( QCloseEvent  *event);

signals:
    void sendMsgToMain(QString msg, int clo);//子线程要发射信号给主窗口

};

#endif // QFORMTABLE_FILE_H
