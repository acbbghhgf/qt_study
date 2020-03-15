#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>

class Butterfly : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Butterfly(QObject *parent = nullptr);
    void timerEvent(QTimerEvent *event);//定时器实现动画的原理是在定时器的timerEvent()中对QGraphicsItem进行重绘
    QRectF boundingRect()const;//为图元限定区域范围，所有继承自QGraphicsItem的自定义图元都必须实现此函数

signals:

public slots:

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);//重绘函数

private:
    bool up;
    QPixmap pix_up;
    QPixmap pix_down;
    qreal angle;

};

#endif // BUTTERFLY_H
