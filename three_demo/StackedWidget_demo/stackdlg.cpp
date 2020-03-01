#include "stackdlg.h"

StackDlg::StackDlg(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("StackedWidget"));
    //新建一个QListWidget控件对象
    list = new QListWidget(this);
    //在新建的QListWidget控件中插入三个条目，作为选择项
    list->insertItem(0, tr("Window1"));
    list->insertItem(1, tr("Window2"));
    list->insertItem(2, tr("Window3"));
    //创建三个QLabel标签控件对象，作为堆栈窗口需要显示的三层窗体。
    label1 = new QLabel(tr("WindowTest1"));
    label2 = new QLabel(tr("WindowTest2"));
    label3 = new QLabel(tr("WindowTest3"));

    //新建一个QStackWidget堆栈窗体对象。
    stack = new QStackedWidget(this);
    //将三个QLabel标签空气依次插入堆栈窗体中。
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    //对整个对话框进行布局。
    //设定对话框的边距
    mainLayout->setMargin(5);
    //设定各个控件之间的间距
    mainLayout->setSpacing(5);
    mainLayout->addWidget(list);
    mainLayout->addWidget(stack, 0, Qt::AlignHCenter);
    //设定可伸缩控件，第一个参数指定设置的控件，第二个参数值大于0表示可伸缩。
    mainLayout->setStretchFactor(list, 1);
    mainLayout->setStretchFactor(stack, 3);

    //将QListWidget的currentRowChanged()信号与堆栈窗体的setCurrentIndex()槽函数连接起来。
    //实现按选择显示窗体，此时的对战窗体index按插入顺序从0依次排序。
    connect(list, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));

}

StackDlg::~StackDlg()
{

}
