#include "mainwidget.h"
#include <QApplication>
#include <QDebug>
#include <QString>

int main(int argc, char *argv[])
{
//---------------------
//    QCoreApplication a(argc, argv);
//    QMap<QString, QString> map;

//    //想栈对象插入<城市，区号>对
//    map.insert("beijing", "111");
//    map.insert("shanghai", "021");
//    map.insert("nanjing", "025");

//    //创建一个只读迭代器
//    for(auto it = map.begin(); it != map.end(); ++it)
//    {
//        qDebug() << " " << it.key() << " " << it.value();
//    }

//    //创建一个读写迭代器
//    QMutableMapIterator<QString,QString> mi(map);
//    if(mi.findNext("111"))
//        mi.setValue("010");

//    QMutableMapIterator<QString, QString> modi(map);

//    qDebug() << "修改后:";

//    for(auto it = map.begin(); it != map.end(); ++it)
//    {
//        qDebug() << " " << it.key() << " " << it.value();
//    }

//    return a.exec();

//--------------

    QCoreApplication a(argc, argv);
    QMap<QString, QString> map;

    //想栈对象插入<城市，区号>对
    map.insert("beijing", "111");
    map.insert("shanghai", "021");
    map.insert("nanjing", "025");

    //创建一个只读迭代器
    QMap<QString,QString>::const_iterator i;
    for(i = map.constBegin(); i != map.constEnd(); ++i)
        qDebug() << " " <<i.key() <<" " <<i.value();

    //创建一个读写迭代器
    QMap<QString,QString>::iterator mi;
    mi = map.find("beijing");
    if(mi != map.end())
        mi.value() = "010";

    qDebug() << "修改后:";

    QMap<QString,QString>::const_iterator modi;
    for(modi = map.constBegin(); modi != map.constEnd(); ++modi)
        qDebug() << " " <<modi.key() <<" " <<modi.value();

    return a.exec();
}
