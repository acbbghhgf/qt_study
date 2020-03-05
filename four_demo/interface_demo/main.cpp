#include "mainwidget.h"
#include <QApplication>
#include <QIcon>
#include <QPixmap>
#include <QSplashScreen>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString strPath = QApplication::applicationDirPath();
    strPath += "/31.jpg";
    a.setWindowIcon(QIcon("31.jpg"));

    QPixmap pixmap("23.png");
    QSplashScreen splash(pixmap);
    splash.resize(pixmap.size());
    splash.show();
    a.processEvents();


    mainWidget w;
    w.setWindowTitle(QObject::tr("光子通讯编解码性能测试及分析软件"));
    w.show();

    return a.exec();
}

