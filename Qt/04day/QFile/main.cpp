#include <QCoreApplication>

#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
#include <QByteArray>
#include <QTextStream>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#if 0
    //1.文件信息
    QFileInfo info("F:\\test.tar.gz");

    qDebug()<<info.absolutePath();
    qDebug()<<info.absoluteFilePath();
    qDebug()<<info.baseName();
    qDebug()<<info.birthTime();
    qDebug()<<info.exists();
    qDebug()<<info.fileName();
    qDebug()<<info.completeSuffix();
#endif
#if 0
    //2.读取文件
    QFile file("F:\\test.c");
    bool ret = file.open(QFile::ReadOnly | QFile::Text);
    if(!ret)
    {
        qDebug()<<"文件打开失败";
        return 1;
    }
    //#if 0
    //2.1第一种方式读取
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        qDebug()<<line;
    }
    file.close();
//#endif
    //2.2第二种方式读取
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        qDebug()<<line;
    }
    file.close();
#endif
    //3.写文件
    QFile file("F:\\test.c");
    bool ret = file.open(QFile::WriteOnly | QFile::Text | QFile::Append);
    if(!ret)
    {
        qDebug()<<"文件打开失败";
        return 1;
    }
#if 0
    QTextStream out(&file);
    out<<"\n//hello world...";
#else
    file.write("\n//file.write() input...");
#endif
    file.close();



    return a.exec();
}
