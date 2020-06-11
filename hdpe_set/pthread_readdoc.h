#ifndef PTHREAD_READDOC_H
#define PTHREAD_READDOC_H

#include    <QThread>

class pthread_readdoc : public QThread
{
    Q_OBJECT

public:
    explicit pthread_readdoc(int nFileIndex);

private:
    int     g_nFileIndex;
    QString SetdataFilepath;
    void    run() Q_DECL_OVERRIDE;//线程任务
    bool    parse_docxfile();//解析定制单word文件
    QString remove_enterline(QString str);

signals:
    void ReaddocSendMsgToMain(QString msg, int flag);//子线程要发射信号给主窗口

};

#endif // PTHREAD_READDOC_H
