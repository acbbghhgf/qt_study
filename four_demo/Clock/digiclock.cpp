#include "digiclock.h"
#include <QTimer>
#include <QTime>
#include <QMouseEvent>


DigiClock::DigiClock(QWidget *parent)
{
    //设置时钟背景
    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::blue);
    setPalette(p);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowOpacity(0.5);

    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));

    timer->start(1000);
    showTime();
    resize(150, 60);
    showColon = true;
}

void DigiClock::showTime()
{
    QTime time = QTime::currentTime();//获取当前系统时间，保存在一个QTime对象中。
    QString text = time.toString("hh:mm");//把获取的当前时间转换成字符串类型。

    //showColon控制电子时钟闪显功能。有timer定时器每秒进行一次当前函数的触发。
    if(showColon)
    {
        text[2] = ';';
        showColon = false;
    }
    else
    {
        text[2] = ' ';
        showColon = true;
    }
    display(text);//显示转换好的字符串时间
}

void DigiClock::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    }
    if(event->button() == Qt::RightButton)
    {
        close();
    }
}

void DigiClock::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - dragPosition);
        event->accept();
    }
}
