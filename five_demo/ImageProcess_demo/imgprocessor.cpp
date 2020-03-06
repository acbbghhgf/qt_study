#include "imgprocessor.h"

ImgProcessor::ImgProcessor(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Easy Word"));    //窗口标题

    showWidget = new ShowWidget(this);
    setCentralWidget(showWidget);

    //创建动作、菜单、工具栏
    createActions();
    createMenus();
    createToolBars();

    if(img.load("mage.png"))
    {
        //在imagelabel中放置图像
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }
}

ImgProcessor::~ImgProcessor()
{
}

void ImgProcessor::createActions()
{
    //“打开”动作
    openFileAction = new QAction(QIcon("open.png"), tr("打开"), this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip(tr("打开一个文件"));

    //“新建”动作
    NewFileAction = new QAction(QIcon("new.png"), tr("新建"), this);
    NewFileAction->setShortcut(tr("Ctrl+N"));
    NewFileAction->setStatusTip(tr("新建一个文件"));

    //“退出”动作
    exitAction = new QAction(tr("退出"), this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("退出程序"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    //“复制”动作
    copyAction = new QAction(QIcon("copy.png"), tr("复制"), this);
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip(tr("复制文件"));
    connect(copyAction, SIGNAL(triggered()), showWidget->text, SLOT(copy()));

    //“剪切”动作
    cutAction = new QAction(QIcon("cut.png"), tr("剪切"), this);
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("剪切文件"));
    connect(cutAction, SIGNAL(truggered()), showWidget->text, SLOT(cut()));

    //“粘贴”动作
    pasteAction = new QAction(QIcon("paste.png"), tr("粘贴"), this);
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setStatusTip(tr("粘贴文件"));
    connect(pasteAction, SIGNAL(triggered()), showWidget->text, SLOT(paste()));

    //“关于”动作
    aboutAction = new QAction(tr("关于"), this);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(QApplication::aboutQt()));

    //“打印文本”动作
    printTRextAction = new QAction(QIcon("printText.png"), tr("打印文本"), this);
    printTRextAction->setStatusTip(tr("打印一个文本"));


    //“打印图像”动作
    printImageAction = new QAction(QIcon("printImage.png"), tr("打印图像"), this);
    printImageAction->setStatusTip(tr("打印一幅图像"));

    //“放大”动作
    zoomInAction = new QAction(QIcon("zoomin.png"), tr("放大"), this);
    zoomInAction->setStatusTip(tr("放大一张照片"));

    //“缩小”动作
    zoomOutAction = new QAction(QIcon("zoomout.png"), tr("缩小"), this);
    zoomOutAction->setStatusTip(tr("缩小一张照片"));

    //实现图像旋转的动作
    //90
    rotate90Action = new QAction(QIcon("rotate90.png"), tr("旋转90"), this);
    rotate90Action->setStatusTip(tr("将一幅图像旋转90度"));
    //180
    rotate180Action = new QAction(QIcon("rotate180.png"), tr("旋转180"), this);
    rotate180Action->setStatusTip(tr("将一幅图像旋转180度"));
    //270
    rotate270Action = new QAction(QIcon("rotate270.png"), tr("旋转270"), this);
    rotate270Action->setStatusTip(tr("将一副图像旋转270度"));

    //实现图像镜像的动作
    //纵向
    mirrorVerticalAction = new QAction(QIcon("mirrorV.png"), tr("纵向镜像"), this);
    mirrorVerticalAction->setStatusTip(tr("对一幅图像纵向镜像"));

    //横向
    mirrorHorizontalAction = new QAction(QIcon("mirrorH.png"), tr("横向镜像"), this);
    mirrorHorizontalAction->setStatusTip(tr("对一副图像横向镜像"));

    //实现撤销和恢复动作
    undoAction = new QAction(QIcon("undo.png"), tr("撤销"), this);
    connect(undoAction, SIGNAL(triggered()), showWidget->text, SLOT(undo()));

    redoAction = new QAction(QIcon("redo.png"), tr("重做"), this);
    connect(redoAction, SIGNAL(triggered()), showWidget->text, SLOT(redo()));
}

void ImgProcessor::createMenus()
{
    //文件菜单
    fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(NewFileAction);
    fileMenu->addAction(printTRextAction);
    fileMenu->addAction(printImageAction);
    fileMenu->addSeparator();//插入空格
    fileMenu->addAction(exitAction);

    //缩放菜单

    //旋转菜单

    //镜像菜单
}

