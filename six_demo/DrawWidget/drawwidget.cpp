#include "drawwidget.h"

Drawwidget::Drawwidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);//对窗体背景色设置
    setPalette(QPalette(Qt::white));
    pix = new QPixmap(size());
    pix->fill(Qt::white);
    setMinimumSize(600, 400);//设置最小尺寸
}

void Drawwidget::setColor(QColor c)
{
    color = c;
}

void Drawwidget::setStyle(int s)
{
    style = s;
}

void Drawwidget::setWidth(int w)
{
    weight = w;
}

void Drawwidget::mousePressEvent(QMouseEvent *event)
{
    startpos = event->pos();
}

void Drawwidget::mouseMoveEvent(QMouseEvent *event)
{
    QPainter *painter = new QPainter;
    QPen pen;
    pen.setStyle((Qt::PenStyle)style);
    pen.setWidth(weight);
    pen.setColor(color);

    painter->begin(pix);
    painter->setPen(pen);
    //绘制直线
    painter->drawLine(startpos, event->pos());
    painter->end();

    startpos = event->pos();

    update();
}

void Drawwidget::paintEvent(QPaintEvent *event)//绘图事件
{
    QPainter p(this);

    p.drawPixmap(QPoint(0,0), *pix);

}

void Drawwidget::resizeEvent(QResizeEvent *event)
{
    if(height() > pix->height() || width() > pix->width())
    {
        QPixmap *newpix = new QPixmap(size());
        newpix->fill(Qt::white);

        QPainter p(newpix);
        p.drawPixmap(QPoint(0, 0), *pix);
        pix = newpix;
    }
    QWidget::resizeEvent(event);//完成其余工作
}

void Drawwidget::clear()
{
    QPixmap *clearpix = new QPixmap(size());
    clearpix->fill(Qt::white);
    pix = clearpix;
    update();
}
