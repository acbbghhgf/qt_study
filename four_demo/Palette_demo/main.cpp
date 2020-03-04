#include "palete.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Palete w;
    w.show();
    return a.exec();
}
