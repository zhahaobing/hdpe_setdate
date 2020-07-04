#include    <QMap>
#include    <QAxObject>
#include    <QDebug>
#include    <ole2.h>
#include    "pthread_readdoc.h"
#include    "mainwindow.h"

static int      g_snBeginReadSet = 0;       //开始读取定值的标志
extern QString  g_szSetdataFilepath;        //定制单文档名,带绝对路径
extern QMap<QString, SETITEM> g_mapSetItem;

pthread_readdoc::pthread_readdoc()
{

}

void pthread_readdoc::run()
{//线程任务
    //QString szLogInfo;

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
    HRESULT ret = OleInitialize(0);
    QAxObject   *workbooks;
    qDebug() << g_szSetdataFilepath << ",at line" << __LINE__ << ".";
    QString     szLogInfo;
    int     nLineCnt = 0;
    //int     nCurLine = 0;
    int     nComargs_flag = 0;      //通讯参数的标志
    int     ip_flag = 0;            //ip地址的标志
    int     netmask_flag = 0;        //子网掩码的标志
    int     gateway_flag = 0;        //子网掩码的标志

    if(ret!=S_OK && ret != S_FALSE)
    {
        return false;
    }

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
    SetdataFilepath = g_szSetdataFilepath;
    SetdataFilepath = SetdataFilepath.replace("/", "\\");
    workbooks->dynamicCall("Open(const QString &)", SetdataFilepath);

    //获取当前活动的Document
    QAxObject *document = myword->querySubObject("ActiveDocument");

    //从当前活动的Document中获取paragraphs
    QAxObject *paragraphs = document->querySubObject("Paragraphs");

    g_snBeginReadSet = 0;
    nLineCnt    = paragraphs->property("Count").toInt();

    //循环输入每一个paragraph
    for (int ipar = 1; ipar <= nLineCnt; ipar++)
    {
        QAxObject *lines = paragraphs->querySubObject("Item(QVariant)", ipar);
        QAxObject *line = lines->querySubObject("Range");
        QString str = line->property("Text").toString();
        //QStringList liststr_1;
        //QStringList liststr_2;
        int nProgressRate   = (100000*ipar)/nLineCnt;

        ReaddocSendMsgToMain(QString::asprintf("%d", nProgressRate), 1);

        line->clear();
        delete line;
        lines->clear();
        delete lines;
        str = str.trimmed();

        str = remove_enterline(str);

        qDebug() << ipar << "," << str << ",file:" << __FILE__ << ",at line " << __LINE__;

        if(ipar >= 1 && ipar <= 5)
        {
            ReaddocSendMsgToMain(str, ipar+1);
        }
        else if(ipar >= 7 && ipar <= 11)
        {
            ReaddocSendMsgToMain(str, ipar+1);
        }

        if(str == QString::fromLocal8Bit("装置版本号"))
        {//装置版本号
            QAxObject *lines_tmp = paragraphs->querySubObject("Item(QVariant)", ipar+1);
            QAxObject *line_tmp = lines_tmp->querySubObject("Range");
            QString str_tmp = line_tmp->property("Text").toString();
            ReaddocSendMsgToMain(str_tmp, 13);
        }
        else if(str == QString::fromLocal8Bit("装置序列号"))
        {//装置序列号
            QAxObject *lines_tmp = paragraphs->querySubObject("Item(QVariant)", ipar+1);
            QAxObject *line_tmp = lines_tmp->querySubObject("Range");
            QString str_tmp = line_tmp->property("Text").toString();
            ReaddocSendMsgToMain(str_tmp, 14);
        }
        else if(str == QString::fromLocal8Bit("装置IED地址"))
        {//装置IED地址
            QAxObject *lines_tmp = paragraphs->querySubObject("Item(QVariant)", ipar+1);
            QAxObject *line_tmp = lines_tmp->querySubObject("Range");
            QString str_tmp = line_tmp->property("Text").toString();
            ReaddocSendMsgToMain(str_tmp, 15);
        }

        //added by zhahaobing for read communication args 2020.07.04 started+++
        if(nComargs_flag == 1)
        {
            if(str == QString::fromLocal8Bit("IP地址"))
            {//初始化第一个IP地址
                QAxObject *lines_tmp = paragraphs->querySubObject("Item(QVariant)", ipar+1);
                QAxObject *line_tmp = lines_tmp->querySubObject("Range");
                QString str_tmp = line_tmp->property("Text").toString();
                if(ip_flag <= 0)
                {
                    ReaddocSendMsgToMain(str_tmp, 20);
                    ip_flag = 1;
                }
                else
                {
                    ReaddocSendMsgToMain(str_tmp, 21);
                }

                //第2个端口的端口名
                lines_tmp = paragraphs->querySubObject("Item(QVariant)", ipar+2);
                line_tmp = lines_tmp->querySubObject("Range");
                str_tmp = line_tmp->property("Text").toString();
                ReaddocSendMsgToMain(str_tmp, 17);
            }

            if(str == QString::fromLocal8Bit("子网掩码"))
            {
                QAxObject *lines_tmp = paragraphs->querySubObject("Item(QVariant)", ipar+1);
                QAxObject *line_tmp = lines_tmp->querySubObject("Range");
                QString str_tmp = line_tmp->property("Text").toString();
                if(netmask_flag <= 0)
                {
                    ReaddocSendMsgToMain(str_tmp, 22);
                    netmask_flag = 1;
                }
                else
                {
                    ReaddocSendMsgToMain(str_tmp, 23);
                }
            }

            if(str == QString::fromLocal8Bit("默认网关"))
            {
                QAxObject *lines_tmp = paragraphs->querySubObject("Item(QVariant)", ipar+1);
                QAxObject *line_tmp = lines_tmp->querySubObject("Range");
                QString str_tmp = line_tmp->property("Text").toString();
                if(gateway_flag <= 0)
                {
                    ReaddocSendMsgToMain(str_tmp, 24);
                    gateway_flag = 1;
                }
                else
                {
                    ReaddocSendMsgToMain(str_tmp, 25);
                }
            }
        }
        if(str == QString::fromLocal8Bit("通讯参数"))
        {
            nComargs_flag = 1;
            //if(str == QString::fromLocal8Bit("") && ip_flag == 2)
            //{//初始化第1个端口的名字
                QAxObject *lines_tmp = paragraphs->querySubObject("Item(QVariant)", ipar+1);
                QAxObject *line_tmp = lines_tmp->querySubObject("Range");
                QString str_tmp = line_tmp->property("Text").toString();
                ReaddocSendMsgToMain(str_tmp, 16);
            //}
        }
        //added by zhahaobing for 读取通信参数 2020.07.04 started+++


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
    OleUninitialize();
    g_snBeginReadSet = 0;

    QMap<QString, SETITEM>::const_iterator iter_column;
    for(iter_column=g_mapSetItem.constBegin(); iter_column != g_mapSetItem.constEnd(); iter_column++)
    {
        qDebug() << iter_column.value().set_addr << iter_column.value().set_name << iter_column.value().set_value << ",at line " << __LINE__;
    }

    qDebug()<< "over!!!";
    szLogInfo = tr("文件") + SetdataFilepath + tr("读取结束！");
    ReaddocSendMsgToMain("over", 0);

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






