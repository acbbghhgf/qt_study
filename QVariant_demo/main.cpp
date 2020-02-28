#include "widget.h"
#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    Widget w;
//    w.show();

//    return a.exec();
//----------------------------
    QApplication a0(argc, argv);

    double a = -19.3, b = 9.7;
    double c = qAbs(a);//返回a的绝对值
    double max = qMax(b, c);//返回两个数值中最大值
    int bn = qRound(b);//返回一个与浮点数最接近的整数值。
    int cn = qRound(c);

    qDebug() << "a = " << a;
    qDebug() << "b = " << b;
    qDebug() << "c = qAbs(a) = " << c;
    qDebug() << "qMax(b,c)" << max;
    qDebug() << "bn = qRound(b) = " << bn;
    qDebug() << "cn = qRound(c) = " << cn;

    qSwap(bn, cn);//交换两个数的值
    qDebug() <<"qSwap(bn, cn) : " << "bn = " << bn << ", cn = " << cn;

    return a0.exec();
}
