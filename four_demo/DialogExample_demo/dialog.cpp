#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    //设置窗口标题
    setWindowTitle(tr("各种标准对话框实例"));

    //标准文件对话框
    fileBtn = new QPushButton(tr("文件标准对话框实例"));
    fileLineEdit = new QLineEdit;

    //标准延时对话框
    colorBtn = new QPushButton(tr("标准颜色对话框实例"));
    colorFrame = new QFrame;
    colorFrame->setFrameShape(QFrame::Box);
    //改变背景颜色
    colorFrame->setAutoFillBackground(true);

    //标准字体对话框
    fontBtn = new QPushButton(tr("标准字体对话框实例"));
    fontLineEdit = new QLineEdit;
    fontLineEdit->setText(tr("Welcome!"));

    //标准输入对话框
    inputBtn = new QPushButton(tr("标准输入对话框实例"));

    //各种消息对话框
    MsgBtn = new QPushButton(tr("标准消息对话框实例"));

    //自定义消息对话框
    CustomBtn = new QPushButton(tr("自定义消息对话框实例"));
    label = new QLabel;
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    //主体布局
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fileBtn, 0, 0);
    mainLayout->addWidget(fileLineEdit, 0, 1);

    mainLayout->addWidget(colorBtn, 1, 0);
    mainLayout->addWidget(colorFrame, 1, 1);

    mainLayout->addWidget(fontBtn, 2, 0);
    mainLayout->addWidget(fontLineEdit, 2, 1);

    mainLayout->addWidget(inputBtn, 3, 0);
    mainLayout->addWidget(MsgBtn, 3, 1);

    mainLayout->addWidget(CustomBtn, 4, 0);
    mainLayout->addWidget(label, 4, 1);


    //实现槽函数链接
    connect(fileBtn, SIGNAL(clicked()), this, SLOT(showFile()));
    connect(colorBtn, SIGNAL(clicked()), this, SLOT(showColor()));
    connect(fontBtn, SIGNAL(clicked()), this, SLOT(showFont()));
    connect(inputBtn, SIGNAL(clicked()), this, SLOT(showInputDlg()));
    connect(MsgBtn, SIGNAL(clicked()), this, SLOT(showMsgDlg()));
    connect(CustomBtn, SIGNAL(clicked()), this, SLOT(showCustomDlg()));

}

Dialog::~Dialog()
{
}

void Dialog::showFile()
{
    //设置标准文件对话框
    QString s = QFileDialog::getOpenFileName(this, "open file dialog", "/", "C++ files(*.cpp);;C files(*.c);;Head files(*.h)");
    fileLineEdit->setText(s);
}

void Dialog::showColor()
{
    //设置标准颜色对话框
    QColor c = QColorDialog::getColor(Qt::blue);
    if(c.isValid())
    {
        colorFrame->setPalette(QPalette(c));
    }
}

void Dialog::showFont()
{
    //设置标准字体对话框
    bool ok;
    QFont f = QFontDialog::getFont(&ok);
    if(ok)
    {
        fontLineEdit->setFont(f);
    }
}

void Dialog::showInputDlg()
{
    inputDlg = new InputDlg(this);
    inputDlg->show();
}

void Dialog::showMsgDlg()
{
    msgDlg = new MsgBoxDlg(this);
    msgDlg->show();
}

void Dialog::showCustomDlg()
{
    label->setText(tr("Custom Message Box"));
    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle(tr("用户自定义消息对话框"));
    QPushButton *yesBtn = customMsgBox.addButton(tr("Yes"), QMessageBox::ActionRole);
    QPushButton *noBtn = customMsgBox.addButton(tr("No"), QMessageBox::ActionRole);
    QPushButton *cancelBtn = customMsgBox.addButton(tr("Cancel"), QMessageBox::ActionRole);

    customMsgBox.setText(tr("这是一个用户自定义消息对话框!"));
    customMsgBox.setIconPixmap(QPixmap("Qt.png"));
    customMsgBox.exec();

    if(customMsgBox.clickedButton() == yesBtn)
        label->setText(tr("Custom message Box/yes"));
    if(customMsgBox.clickedButton() == noBtn)
        label->setText(tr("Custom message Box/no"));
    if(customMsgBox.clickedButton() == cancelBtn)
        label->setText(tr("Custom message Box/cancel"));
    return ;
}
