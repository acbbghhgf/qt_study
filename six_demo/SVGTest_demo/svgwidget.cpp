#include "svgwidget.h"

SvgWidget::SvgWidget(QWidget *parent):QSvgWidget(parent)
{
    render = renderer();
}

void SvgWidget::wheelEvent(QWheelEvent *ev)
{
    const double diff = 0.1;    //缩放比例
    //获取图片当前尺寸
    QSize size = render->defaultSize();
    int width = size.width();
    int height = size.height();
    if(ev->delta() > 0)
    {
        //对图片的长、宽进行处理，放大一定比例
        width = int(this->width() + this->width() * diff);
        height = int(this->height() + this->height() * diff);
    }
    else{
        //对图片的长、宽进行处理，缩小一定比例
        width = int(this->width() - this->width() * diff);
        height = int(this->height() - this->height() * diff);
    }
    resize(width, height);//利用新的长、宽值进行resize操作。
}
