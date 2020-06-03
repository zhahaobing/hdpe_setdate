#include    <QApplication>
#include    <QTextCodec>
#include    <QDate>

#include    "mainwindow.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale()); //设置GBK到本地
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));


    QApplication a(argc, argv);
    MainWindow w;
    static const QDate buildDate = QLocale(QLocale::English).toDate(QString(__DATE__).replace("  "," 0"),"MMM dd yyyy");
    static const QTime buildTime = QTime::fromString(__TIME__, "hh:mm:ss");
    QString wTitle = "HDPE定值计算专用软件";
    wTitle += buildDate.toString("yyyyMMdd") + buildTime.toString("hhmm");
    w.setWindowTitle(wTitle);

    w.show();
    return a.exec();
}
