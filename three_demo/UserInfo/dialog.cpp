#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("UserInfo"));
    //-----------左侧--------
    UserNameLabel = new QLabel(tr("用户名："));
    UserNameLineEdit = new QLineEdit;
    NameLabel = new QLabel(tr("姓名："));
    NameLineEdit = new QLineEdit;
    SexComboBox = new QComboBox;
    SexComboBox->addItem(tr("女"));
    SexComboBox->addItem(tr("男"));
    DepartmentLabel = new QLabel(tr("部门："));
    DepartmentTextEdit = new QTextEdit;
    AgeLabel = new QLabel(tr("年龄："));
    AgeLineEdit = new QLineEdit;
    OtherLabel = new QLabel(tr("备注："));
    //设定控件风格，setFrameStyle（）是QFrame的方法。参数指定由形状（shape）和阴影（shadow）配合设定
    //六种形状：NoFrame、Panel、Box、HLine、VLine及WinPanel；
    //三种阴影：Plain、Raised及Sunken。
    OtherLabel->setFrameStyle(QFrame::Panel |QFrame::Sunken);

    //左部布局，由于不是主布局管理器，所以不指定父窗口
    LeftLayout = new QGridLayout();
    //向布局中加入需要布局的控件
    LeftLayout->addWidget(UserNameLabel, 0, 0);
    LeftLayout->addWidget(UserNameLineEdit, 0, 1);
    LeftLayout->addWidget(NameLabel, 1, 0);
    LeftLayout->addWidget(NameLineEdit, 1, 1);
    LeftLayout->addWidget(SexLabel, 2, 0);
    LeftLayout->addWidget(SexComboBox, 2, 1);
    LeftLayout->addWidget(DepartmentLabel, 3, 0);
    LeftLayout->addWidget(DepartmentTextEdit, 3, 1);
    LeftLayout->addWidget(AgeLabel, 4, 0);
    LeftLayout->addWidget(AgeLineEdit, 4, 1);
    LeftLayout->addWidget(OtherLabel, 5, 0, 1, 2);
    //setColumnStretch()设定占用空间比例。
    //第一列和第二列比例为1:3.即使对话框框架大小改变，该比例也不会改变
    LeftLayout->setColumnStretch(0, 1);
    LeftLayout->setColumnStretch(1, 3);

    //-------------右侧----------
    HeadLabel = new QLabel(tr("头像："));
    HeadIconLabel = new QLabel;
    QPixmap icon("321.bmp");
    HeadIconLabel->setPixmap(icon);
    HeadIconLabel->resize(icon.width(), icon.height());
    UpdateHeadBtn = new QPushButton(tr("更新"));
    //完成右上侧头像选择区的布局
    TopRightLayout = new QHBoxLayout();
    //设定各个控件之间的间距
    TopRightLayout->setSpacing(20);
    TopRightLayout->addWidget(HeadLabel);
    TopRightLayout->addWidget(HeadIconLabel);
    TopRightLayout->addWidget(UpdateHeadBtn);
    IntroductionLabel = new QLabel(tr("个人说明："));
    IntroductionTextEdit = new QTextEdit;

    //完成右侧布局
    RightLayout = new QVBoxLayout();
    RightLayout->setMargin(10);
    RightLayout->addLayout(TopRightLayout);
    RightLayout->addWidget(IntroductionLabel);
    RightLayout->addWidget(IntroductionTextEdit);

    //--------------底部--------------
    OKBtn = new QPushButton(tr("确定"));
    CancelBtn = new QPushButton(tr("取消"));
    //完成下面两个按钮的布局
    ButtomLayout = new QHBoxLayout();
    //在按钮之前插入一个占位符，是的两个按钮靠右对齐，并且整个对话框大小改变时按钮大小不改变。
    ButtomLayout->addStretch();
    ButtomLayout->addWidget(OKBtn);
    ButtomLayout->addWidget(CancelBtn);

    //------------------总体布局----------------
    //实现主布局，指定父窗口（this），也可以调用 this->setLayout(mainLayout)实现。
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(LeftLayout, 0, 0);
    mainLayout->addLayout(RightLayout, 0, 1);
    mainLayout->addLayout(ButtomLayout, 1, 0, 1, 2);
    //设定最优化显示，并且用户无法改变对话框大小
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

}

Dialog::~Dialog()
{

}
