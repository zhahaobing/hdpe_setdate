#ifndef PTHREAD_READDOC_H
#define PTHREAD_READDOC_H

#include    <QThread>

class pthread_readdoc : public QThread
{
    Q_OBJECT

public:
    pthread_readdoc();

private:
    void    run() Q_DECL_OVERRIDE;//线程任务
    bool    parse_docxfile();//解析定制单word文件
    QString remove_enterline(QString str);

};

#endif // PTHREAD_READDOC_H
