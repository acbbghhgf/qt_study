#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap("15.png");
    QSplashScreen splash(pixmap);
    splash.resize(pixmap.size());
    splash.show();
    a.processEvents();


    MainWindow w;
    w.show();

    splash.finish(&w);

    return a.exec();
}
