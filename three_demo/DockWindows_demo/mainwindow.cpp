#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("DockWindows"));
    QTextEdit *te = new QTextEdit(this);
    te->setText(tr("Main Window"));
    te->setAlignment(Qt::AlignCenter);

    //停靠窗口1
    QDockWidget *dock = new QDockWidget(tr("DockWindow1"), this);
/*
 * void setFeatures(DockWidgetFeatures features);
 * 参数指定停靠窗体的特性，包括以下几种参数：
 * QDockWidget::DockWidgetClosable：停靠窗体可关闭。
 * QDockWidget::DockWidgetMovable：停靠窗体可移动。
 * QDockWidget::DockWidgetFloatable:停靠窗体可浮动。
 * QDockWidget::AllDockWidgetFeatures：此参数表示拥有停靠窗体的所有特性。
 * QDockWidget::NoDockWidgetFeatures：不可一定、不可关闭、不可浮动。
*/
    dock->setFeatures(QDockWidget::DockWidgetMovable);
/*
 * void setAllowedAreas(Qt::DockWidgetAreas areas);
 * 参数指定了停靠窗体可停靠的区域，包括以下几种参数：
 * Qt::LeftDockWidgetArea：可在主窗口的左侧停靠。
 * Qt::RightDockWidgetArea：可在主窗口的右侧停靠。
 * Qt::TopDockWidgetArea：可在主窗口的顶端停靠。
 * Qt::BottomDockWidgetArea：可在主窗口的底部停靠。
 * Qt::AllDockWidgetArea：可在主窗口任意部位停靠。
 * Qt::NoDockDockWidgetArea：只能停靠在插入处。
*/
    dock->setAllowedAreas(Qt::LeftDockWidgetArea |Qt::RightDockWidgetArea);
    QTextEdit *te1 = new QTextEdit();
    te1->setText(tr("Window1, The dock widget can be moved between docks by the user" ""));
    dock->setWidget(te1);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    //停靠窗口2
    dock = new QDockWidget(tr("DockWindow2"), this);
    dock->setFeatures(QDockWidget::DockWidgetClosable |QDockWidget::DockWidgetFloatable);
    QTextEdit *te2 = new QTextEdit();
    te2->setText(tr("Window2, The dock widget can be detached from the main window,""and float as an independent window, and can be closed"));
    dock->setWidget(te2);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    //停靠窗口3
    dock = new QDockWidget(tr("DockWindow3"), this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    QTextEdit *te3 = new QTextEdit();
    te3->setText(tr("Window3, The dock widget can be closed, moved, and floated"));
    dock->setWidget(te3);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

MainWindow::~MainWindow()
{

}
