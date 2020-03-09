#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QDebug>

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    enum Shape{Line, Rectangle, RoundRect, Ellipse, Polygon, Polyline, Points,\
               Arc, Path, Text, Pixmap};
    explicit PaintArea(QWidget *parent = 0);

    //设置绘图形状
    void setShap(Shape);
    //设置画笔
    void setPen(QPen);
    //设置画刷
    void setBrush(QBrush);
    //设置填充
    void setFillRule(Qt::FillRule);
    //设置重画事件
    void paintEvent(QPaintEvent *event);

signals:

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    Qt::FillRule fillRule;

};

#endif // PAINTAREA_H
