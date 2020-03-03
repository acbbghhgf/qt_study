#include "drawer.h"

Drawer::Drawer(QWidget *parent, Qt::WindowFlags f)
{
    //设置主窗口标题
    setWindowTitle(tr("My QQ"));

    toolBtn1_1 = new QToolButton;
    toolBtn1_1->setText(tr("张三"));
    toolBtn1_1->setIcon(QPixmap("11.jpg"));
    toolBtn1_1->setIconSize(QPixmap("11.jpg").size());
    toolBtn1_1->setAutoRaise(true);
    toolBtn1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_2 = new QToolButton;
    toolBtn1_2->setText(tr("李四"));
    toolBtn1_2->setIcon(QPixmap("12.jpg"));
    toolBtn1_2->setIconSize(QPixmap("12.jpg").size());
    toolBtn1_2->setAutoRaise(true);
    toolBtn1_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_3 = new QToolButton;
    toolBtn1_3->setText(tr("王五"));
    toolBtn1_3->setIcon(QPixmap("13.jpg"));
    toolBtn1_3->setIconSize(QPixmap("13.jpg").size());
    toolBtn1_3->setAutoRaise(true);
    toolBtn1_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_4 = new QToolButton;
    toolBtn1_4->setText(tr("小孙"));
    toolBtn1_4->setIcon(QPixmap("14.jpg"));
    toolBtn1_4->setIconSize(QPixmap("14.jpg").size());
    toolBtn1_4->setAutoRaise(true);
    toolBtn1_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_5 = new QToolButton;
    toolBtn1_5->setText(tr("小赵"));
    toolBtn1_5->setIcon(QPixmap("15.jpg"));
    toolBtn1_5->setIconSize(QPixmap("15.jpg").size());
    toolBtn1_5->setAutoRaise(true);
    toolBtn1_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox1 = new QGroupBox;
    QVBoxLayout *layout1 = new QVBoxLayout(groupBox1);

    //布局中各窗体的显示间距
    layout1->setMargin(10);
    //布局中各窗体的显示位置，居中
    layout1->setAlignment(Qt::AlignCenter);
    //插入各个按钮
    layout1->addWidget(toolBtn1_1);
    layout1->addWidget(toolBtn1_2);
    layout1->addWidget(toolBtn1_3);
    layout1->addWidget(toolBtn1_4);
    layout1->addWidget(toolBtn1_5);

    //插入一个占位符
    layout1->addStretch();

    toolBtn2_1 = new QToolButton;
    toolBtn2_1->setText(tr("小王"));
    toolBtn2_1->setIcon(QPixmap("21.jpg"));
    toolBtn2_1->setIconSize(QPixmap("21.jpg").size());
    toolBtn2_1->setAutoRaise(true);
    toolBtn2_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn2_2 = new QToolButton;
    toolBtn2_2->setText(tr("小张"));
    toolBtn2_2->setIcon(QPixmap("22.jpg"));
    toolBtn2_2->setIconSize(QPixmap("22.jpg").size());
    toolBtn2_2->setAutoRaise(true);
    toolBtn2_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox2 = new QGroupBox;
    QVBoxLayout *layout2 = new QVBoxLayout(groupBox2);
    layout2->setMargin(10);
    layout2->setAlignment(Qt::AlignCenter);
    layout2->addWidget(toolBtn2_1);
    layout2->addWidget(toolBtn2_2);

    toolBtn3_1 = new QToolButton;
    toolBtn3_1->setText(tr("小陈"));
    toolBtn3_1->setIcon(QPixmap("31.jpg"));
    toolBtn3_1->setIconSize(QPixmap("31.jpg").size());
    toolBtn3_1->setAutoRaise(true);
    toolBtn3_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn3_1 = new QToolButton;
    toolBtn3_1->setText(tr("小李"));
    toolBtn3_1->setIcon(QPixmap("32.jpg"));
    toolBtn3_1->setIconSize(QPixmap("32.jpg").size());
    toolBtn3_1->setAutoRaise(true);
    toolBtn3_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox3 = new QGroupBox;
    QVBoxLayout *layout3 = new QVBoxLayout(groupBox3);
    layout3->setMargin(10);
    layout3->setAlignment(Qt::AlignCenter);
    layout3->addWidget(toolBtn3_1);
    layout3->addWidget(toolBtn3_2);

    //将准备好的抽屉插入Toolbox中
    this->addItem((QWidget *)groupBox1, tr("我的好友"));
    this->addItem((QWidget *)groupBox2, tr("陌生人"));
    this->addItem((QWidget *)groupBox3, tr("黑名单"));

}
