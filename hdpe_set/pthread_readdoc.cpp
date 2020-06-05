#include    <QMap>
#include    <QAxObject>
#include    <QDebug>
#include    "pthread_readdoc.h"

extern QString g_szSetdataFilepath; //定制单文档名,带绝对路径

pthread_readdoc::pthread_readdoc()
{

}

void pthread_readdoc::run()
{//线程任务
    QString szLogInfo;
    if(!parse_docxfile())
    {
        goto ERR_RESULT;
    }

ERR_RESULT:

    return;
}

bool pthread_readdoc::parse_docxfile()
{
    QAxObject   *myword     = new QAxObject(this);
    QAxObject   *workbooks;
    qDebug() << g_szSetdataFilepath << ",at line" << __LINE__ << ".";

    if (myword->setControl("Word.Application"))
    {

    }
    else
    {
        myword->setControl("ket.Application");  //连接Excel控件
    }

    myword->setProperty("visible", false); //true 表示操作文件时可见，false表示为不可见
    workbooks = myword->querySubObject("Documents");

    //通过Document打开要获取文件内容的文件
    g_szSetdataFilepath = g_szSetdataFilepath.replace("/", "\\");
    workbooks->dynamicCall("Open(const QString &)", g_szSetdataFilepath);

    //获取当前活动的Document
    QAxObject *document = myword->querySubObject("ActiveDocument");

#if 0

    //从当前活动的Document中获取paragraphs
    QAxObject *paragraphs = document->querySubObject("Paragraphs");

    //循环输入每一个paragraph
    for (int ipar = 1; ipar <= paragraphs->property("Count").toInt(); ipar++)
    {
        QAxObject *lines = paragraphs->querySubObject("Item(QVariant)", ipar);
        QAxObject *line = lines->querySubObject("Range");
        QString str = line->property("Text").toString();
        line->clear();
        delete line;
        lines->clear();
        delete lines;
        str = str.trimmed();
        qDebug()<<str;
    }

#endif
    QAxObject* my_table = myword->querySubObject("Tables"); //获取所有表格
    //QAxBase::PropertyBag p = m_document->propertyBag();
    int tablecount = -1;
    if (NULL != my_table)
    {
        tablecount = my_table->dynamicCall("Count").toInt(); //获取表格个数
        delete my_table;
        my_table = NULL;
    }
    qDebug()<<"tablecount:"<<tablecount<<",at line " << __LINE__;


    /*QAxObject *my_table = myword->querySubObject("Tables(int)", 0); //获取表格
    if(!my_table)
    {
        qDebug()<<"no tables, at line " << __LINE__;
        return false;
    }*/

    //关闭Document
    document->dynamicCall("Close (boolean)", false);
    myword->dynamicCall("Quit()");

    return true;
}













