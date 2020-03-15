#include "svgwindow.h"

SvgWindow::SvgWindow(QWidget *parent):QScrollArea(parent)
{
    svgWidget = new SvgWidget;
    setWidget(svgWidget);//设置滚动区窗体
}

void SvgWindow::setFile(QString fileName)
{
    svgWidget->load(fileName);//加载新文件并显示
    QSvgRenderer *render = svgWidget->renderer();
    svgWidget->resize(render->defaultSize());//使窗体安装SVG图片默认尺寸进行显示。
}

void SvgWindow::mousePressEvent(QMouseEvent *ev)
{
    mousePressPos = ev->pos();
    scrollBarValuesOnMousePress.rx() = horizontalScrollBar()->value();
    scrollBarValuesOnMousePress.ry() = verticalScrollBar()->value();
    ev->accept();
}

void SvgWindow::mouseMoveEvent(QMouseEvent *ev)
{
    horizontalScrollBar()->setValue(scrollBarValuesOnMousePress.x()- ev->pos().x() + mousePressPos.x());//设置水平滑轮新位置
    verticalScrollBar()->setValue(scrollBarValuesOnMousePress.y() - ev->pos().y() + mousePressPos.y());//对垂直滑轮进行设置

    horizontalScrollBar()->update();
    verticalScrollBar()->update();
    ev->accept();
}
