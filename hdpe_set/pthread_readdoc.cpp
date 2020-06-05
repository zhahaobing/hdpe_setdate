#include    <QMap>
#include    <QAxObject>
#include    <QDebug>
#include    "pthread_readdoc.h"
#include    "mainwindow.h"

static int      g_snBeginReadSet = 0;       //开始读取定值的标志
extern QString  g_szSetdataFilepath;    //定制单文档名,带绝对路径
extern QMap<QString, SETITEM> g_mapSetItem;

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

    //从当前活动的Document中获取paragraphs
    QAxObject *paragraphs = document->querySubObject("Paragraphs");

    g_snBeginReadSet = 0;
    //循环输入每一个paragraph
    for (int ipar = 1; ipar <= paragraphs->property("Count").toInt(); ipar++)
    {
        QAxObject *lines = paragraphs->querySubObject("Item(QVariant)", ipar);
        QAxObject *line = lines->querySubObject("Range");
        QString str = line->property("Text").toString();
        //QStringList liststr_1;
        //QStringList liststr_2;

        line->clear();
        delete line;
        lines->clear();
        delete lines;
        str = str.trimmed();

        str = remove_enterline(str);

        //qDebug()<< str <<",at line " << __LINE__;

        switch(g_snBeginReadSet) {
            case 0:
            {
                if(str == QString::fromLocal8Bit("定"))
                {
                    g_snBeginReadSet++;
                }

                break;
            }
            case 1:
            {
                if(str == QString::fromLocal8Bit("值"))
                {
                    g_snBeginReadSet++;
                }
                else if( str.length() <= 0 )
                {

                }
                else
                {
                   g_snBeginReadSet = 0;
                }
                break;
            }
            case 2:
            {
                if(str == QString::fromLocal8Bit("内"))
                {
                    g_snBeginReadSet++;
                }
                else if( str.length() <= 0 )
                {

                }
                else
                {
                    g_snBeginReadSet = 0;
                }
                break;
            }
            case 3:
            {
                if(str == QString::fromLocal8Bit("容"))
                {
                    g_snBeginReadSet++;
                }
                else if( str.length() <= 0 )
                {

                }
                else
                {
                    g_snBeginReadSet = 0;
                }
                break;
            }
            default:
                break;
        }//end of switch(g_snBeginReadSet)
        //qDebug()<< str <<",at line " << __LINE__;

        if(g_snBeginReadSet >= 4)
        {
            //qDebug()<< str <<",at line " << __LINE__;

            int j = 0;
            int k = 0;
            SETITEM setItemTmp;

            if(str.toInt() < 9999 && str.toInt() > 0 && (str.size() == 4))
            {
                //qDebug()<< str <<",at line " << __LINE__;
                setItemTmp.set_addr = str;
            }
            else
            {
                continue;
            }

            for(j=1;j<10;j++) {
                QAxObject *lines_1 = paragraphs->querySubObject("Item(QVariant)", ipar+j);
                QAxObject *line_1 = lines_1->querySubObject("Range");
                QString str_1 = line_1->property("Text").toString();
                line_1->clear();
                delete line_1;
                lines_1->clear();
                delete lines_1;


                setItemTmp.set_name = str_1.trimmed();
                setItemTmp.set_name = remove_enterline(setItemTmp.set_name);
                if(setItemTmp.set_name.toInt() < 9999 && setItemTmp.set_name.toInt() > 0 && (setItemTmp.set_name.size() == 4))
                {
                    setItemTmp.set_name = "";
                    setItemTmp.set_name.clear();
                    break;
                }

                if(setItemTmp.set_name.length() > 0)
                {
                    break;
                }
            }

            for(k=j+1; k< 10; k++) {
                QAxObject *lines_2 = paragraphs->querySubObject("Item(QVariant)", ipar+k);
                QAxObject *line_2 = lines_2->querySubObject("Range");
                QString str_2 = line_2->property("Text").toString();
                line_2->clear();
                delete line_2;
                lines_2->clear();
                delete lines_2;

                setItemTmp.set_value = str_2.trimmed();
                setItemTmp.set_value = remove_enterline(setItemTmp.set_value);
                if(setItemTmp.set_value.toInt() < 9999 && setItemTmp.set_value.toInt() > 0 && (setItemTmp.set_value.size() == 4))
                {
                    setItemTmp.set_value = "";
                    setItemTmp.set_value.clear();
                    break;
                }
                if(setItemTmp.set_value.length() > 0)
                {
                    break;
                }
            }

            if(setItemTmp.set_addr.length() > 0 &&
               setItemTmp.set_name.length() > 0 &&
               setItemTmp.set_value.length() > 0) {
                g_mapSetItem.insert(QString::asprintf("%08d",ipar) ,setItemTmp);
            }
//            qDebug()<< "set_addr"<< setItemTmp.set_addr << ",at line " << __LINE__;
//            qDebug()<< "set_name"<< setItemTmp.set_name << ",at line " << __LINE__;
//            qDebug()<< "set_value"<< setItemTmp.set_value << ",at line " << __LINE__;

        }
        //qDebug()<<str;
    }

#if 0
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
#endif

    //关闭Document
    document->dynamicCall("Close (boolean)", false);
    myword->dynamicCall("Quit()");
    g_snBeginReadSet = 0;

    QMap<QString, SETITEM>::const_iterator iter_column;
    for(iter_column=g_mapSetItem.constBegin(); iter_column != g_mapSetItem.constEnd(); iter_column++)
    {
        qDebug() << iter_column.value().set_addr << iter_column.value().set_name << iter_column.value().set_value << ",at line " << __LINE__;
    }

    qDebug()<< "over!!!";

    return true;
}


/******************************************************************************
 * 函数：remove_enterline
 * 功能：去除字符的转义换行
 * 参数：QString str,源字符串
 * 返回值： QString，目的字符串
 *****************************************************************************/
QString pthread_readdoc::remove_enterline(QString str)
{
    //return str;

    QStringList liststr_1 = str.split("\r");
    QStringList liststr_2;
    QString strTmp = liststr_1[0];

    liststr_2 = strTmp.split("\u0007");
    strTmp = liststr_2[0];

    return strTmp;
}






