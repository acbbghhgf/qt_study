#include "content.h"
#include <QApplication>
#include <QTextCodec>
#include <QSplitter>
#include <QListWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //设置整个程序使用的字体和字号
    QFont font("AR PL KaitiM GB", 12);
    a.setFont(font);

    //新建一个水平分割窗口对象，作为主布局框
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0);
    splitterMain->setOpaqueResize(true);
    QListWidget *list = new QListWidget(splitterMain);
    list->insertItem(0, QObject::tr("基本信息"));
    list->insertItem(1, QObject::tr("联系方式"));
    list->insertItem(2, QObject::tr("详细资料"));
    Content *content = new Content(splitterMain);
    QObject::connect(list, SIGNAL(currentRowChanged(int)), content->stack, SLOT(setCurrentIndex(int)));
    //设置主布局框的标题
    splitterMain->setWindowTitle(QObject::tr("修改用户资料"));
    //设置主布局框的最小尺寸
    splitterMain->setMinimumSize(splitterMain->minimumSize());
    //设置主布局框的最大尺寸
    splitterMain->setMaximumSize(splitterMain->maximumSize());

    //显示主布局框
    splitterMain->show();

//    Content w;
//    w.show();

    return a.exec();
}
