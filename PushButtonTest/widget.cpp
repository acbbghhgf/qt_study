#include "widget.h"
#include <qapplication.h>
#include <qpushbutton.h>
#include <qfont.h>
#include <QLabel>
#include <QDate>
#include <QDateTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(200, 120);
    setMaximumSize(200, 120);
    QPushButton *quit = new QPushButton("Quit", this);
    quit->setGeometry(62, 40, 75, 30);
    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QLabel *datalbel = new QLabel();
    QDateTime *datatime = new QDateTime(QDateTime::currentDateTime());
    datalbel->setText(datatime->date().toString());
    datalbel->show();
}

Widget::~Widget()
{

}
