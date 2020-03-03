#include "msgboxdlg.h"

MsgBoxDlg::MsgBoxDlg(QWidget *parent)
{
    setWindowTitle(tr("标准对话框实例"));
    label = new QLabel(tr("请选择一种消息框"));
    questionBtn = new QPushButton(tr("QusetionMsg"));
    informationBtn = new QPushButton(tr("InformationMsg"));
    warningBtn = new QPushButton(tr("warningMsg"));
    criticalBtn = new QPushButton(tr("criticalMsg"));
    aboutBtn = new QPushButton(tr("aboutMsg"));
    aboutQtBtn = new QPushButton(tr("aboutQtMsg"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label, 0, 0, 1, 2);
    mainLayout->addWidget(questionBtn, 1, 0);
    mainLayout->addWidget(informationBtn, 1, 1);
    mainLayout->addWidget(warningBtn, 2, 0);
    mainLayout->addWidget(criticalBtn, 2, 1);
    mainLayout->addWidget(aboutBtn, 3, 0);
    mainLayout->addWidget(aboutQtBtn, 3, 1);

    connect(questionBtn, SIGNAL(clicked()), this , SLOT(showQuestionMsg()));
    connect(informationBtn, SIGNAL(clicked()), this , SLOT(showInformationMsg()));
    connect(warningBtn, SIGNAL(clicked()), this , SLOT(showWarningMsg()));
    connect(criticalBtn, SIGNAL(clicked()), this , SLOT(showCriticalMsg()));
    connect(aboutBtn, SIGNAL(clicked()), this , SLOT(showAboutMsg()));
    connect(aboutQtBtn, SIGNAL(clicked()), this , SLOT(showAboutQtMsg()));

}

void MsgBoxDlg::showQuestionMsg()
{
    //question消息对话框
    label->setText(tr("question message box"));
    switch (QMessageBox::question(this, tr("question消息框"), tr("您现在已经修改完成，是否结束程序"), QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok)) {
    case QMessageBox::Ok:
        label->setText("Question button/OK");
        break;
    case QMessageBox::Cancel:
        label->setText("Question button/Cancel");
        break;
    default:
        break;
    }
    return ;
}

void MsgBoxDlg::showInformationMsg()
{
    //information消息框
    label->setText(tr("Information Message Box"));
    QMessageBox::information(this, tr("information消息框"), tr("这个information消息框测试，欢迎您！"));
    return ;
}

void MsgBoxDlg::showWarningMsg()
{
    //warning消息框
    label->setText(tr("warning message box"));
    switch (QMessageBox::warning(this, tr("warning消息框"), tr("您修改的内容还未保存，是否要保存对文档的修改？"), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel, QMessageBox::Save)) {
    case QMessageBox::Save:
        label->setText("Warning button/Save");
        break;
    case QMessageBox::Discard:
        label->setText("Warning button/Discard");
        break;
    case QMessageBox::Cancel:
        label->setText("Warning button/Cancel");
        break;
    default:
        break;
    }
    return ;
}

void MsgBoxDlg::showCriticalMsg()
{
    //critical消息框
    label->setText(tr("critical message box"));
    QMessageBox::critical(this, tr("critical消息框"), tr("这是一个critical消息框测试！"));
    return ;
}

void MsgBoxDlg::showAboutMsg()
{
    //about消息框
    label->setText(tr("about message box"));
    QMessageBox::about(this, tr("about消息框"), tr("这是一个about消息框测试！"));
    return ;
}

void MsgBoxDlg::showAboutQtMsg()
{
    //about Qt消息框
    label->setText(tr("about message box"));
    QMessageBox::aboutQt(this, tr("about Qt消息框"));
    return ;
}
