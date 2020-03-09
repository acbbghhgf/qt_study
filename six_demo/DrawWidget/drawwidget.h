#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QColor>
#include <QPoint>
#include <QMouseEvent>
#include <QPainter>

class Drawwidget : public QWidget
{
    Q_OBJECT
public:
    explicit Drawwidget(QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

signals:

public slots:
    void setStyle(int);//设置风格
    void setWidth(int);//设置宽度
    void setColor(QColor);//设置颜色
    void clear();//清空画面

private:
    QPixmap *pix;
    QPoint startpos;
    QPoint endpos;
    int style;
    int weight;
    QColor color;
};

#endif // DRAWWIDGET_H
