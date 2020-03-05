#include "mainwidget.h"
#include "ui_mainwidget.h"

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    setWindowTitle(tr("光子通讯编解码性能测试及分析软件"));
    ui->setupUi(this);
    setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(backgroundRole(), QPixmap("22.jpg"));
    setPalette(pal);

    ui->textEdit->append(tr("单光子通讯发送服务端异常，请检查设置!"));


}

mainWidget::~mainWidget()
{
    delete ui;
}
