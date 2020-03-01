#include "mainwindow.h"
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont font("ZYSong18030", 12);
    a.setFont(font);
    //主分割窗口
    //新建一个QSplitter类对象，作为主分割窗口，设定此分割窗口为水平分割窗口
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0);
    //新建一个QTextEdit类对象，并将其插入主分割窗口中。
    QTextEdit *texteft = new QTextEdit(QObject::tr("Left Widget"), splitterMain);
    //设定TextEdit中文字的对齐复方石，常用有
    //Qt::AlignLeft-做对齐;Qt::AlignRight-右对齐；Qt::AlignCenter-文字居中。
    //Qt::AlignUp-文字与顶端对齐；Qt::AlignBotton：文字与底端对齐。
    texteft->setAlignment(Qt::AlignCenter);

    //右分割窗口
    //新建一个QSplitter类对象，作为右分割窗口，设定此分割窗口为垂直分割窗口，并以主分割窗口为父窗口。
    QSplitter *splitterRight = new QSplitter(Qt::Vertical, splitterMain);
    //设定分割窗口的分隔条在拖拽时是否为实时更新显示，为true则实时更新，false则在拖拽到位并释放鼠标后更新显示，默认为true。
    splitterRight->setOpaqueResize(false);
    QTextEdit *textup = new QTextEdit(QObject::tr("Top Widget"), splitterRight);
    textup->setAlignment(Qt::AlignCenter);
    QTextEdit *textBottom = new QTextEdit(QObject::tr("Bottom Widget"), splitterRight);
    textBottom->setAlignment(Qt::AlignCenter);

    //设定可伸缩控件，第一个参数为指定设置的控件序号（序号按控件插入顺序从0逐步增加）；
    //第二个参数为大于0的值，表示为可伸缩控件。
    //序号1的控件为右分割窗口，当整个对话框的宽度发送变化后，左边窗口的宽度不变，右边会随拉伸而改变。
    splitterMain->setStretchFactor(1, 1);
    splitterMain->setWindowTitle(QObject::tr("Splitter"));
    splitterMain->show();

//    MainWindow w;
//    w.show();

    return a.exec();
}
