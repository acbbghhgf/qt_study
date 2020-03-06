#include "imgprocessor.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QColor>
#include <QColorDialog>

ImgProcessor::ImgProcessor(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Easy Word"));    //窗口标题

    showWidget = new ShowWidget(this);
    setCentralWidget(showWidget);

    //在工具栏上嵌入控件
    //设置字体
    fontLabel = new QLabel(tr("字体:"));
    fontComboBox = new QFontComboBox;
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);
    fontLabel2 = new QLabel(tr("字号:"));
    sizeComboBox = new QComboBox;
    QFontDatabase db;
    foreach(int size, db.standardSizes())
        sizeComboBox->addItem(QString::number(size));
    boldBtn = new QToolButton;
    boldBtn->setIcon(QIcon("bold.png"));
    boldBtn->setCheckable(true);
    italicBtn = new QToolButton;
    italicBtn->setIcon(QIcon("italic.png"));
    italicBtn->setCheckable(true);
    underlineBtn = new QToolButton;
    underlineBtn->setIcon(QIcon("under.png"));
    underlineBtn->setCheckable(true);
    colorBtn = new QToolButton;
    colorBtn->setIcon(QIcon("color.png"));
    colorBtn->setCheckable(true);

    //创建动作、菜单、工具栏
    createActions();
    createMenus();
    createToolBars();

    if(img.load("mage.png"))
    {
        //在imagelabel中放置图像
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }

    connect(fontComboBox, SIGNAL(activated(QString)), this, SLOT(ShowFontComboBox(QString)));
    connect(sizeComboBox, SIGNAL(activated(QString)), this, SLOT(ShowSizeSpinBox(QString)));
    connect(boldBtn, SIGNAL(clicked()), this, SLOT(ShowBoldBtn()));
    connect(italicBtn, SIGNAL(clicked()), this, SLOT(ShowItalicBtn()));
    connect(underlineBtn, SIGNAL(clicked()), this, SLOT(ShowUnderlineBtn()));
    connect(colorBtn, SIGNAL(clicked()), this, SLOT(ShowColorBtn()));
    connect(showWidget->text, SIGNAL(currentCharFormatChanged(QTextCharFormat &)), this, SLOT(ShowCurrentFormatChanged(const QTextCharFormat &)));
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
    connect(openFileAction, SIGNAL(triggered()), this, SLOT(showOpenFile()));

    //“新建”动作
    NewFileAction = new QAction(QIcon("new.png"), tr("新建"), this);
    NewFileAction->setShortcut(tr("Ctrl+N"));
    NewFileAction->setStatusTip(tr("新建一个文件"));
    connect(NewFileAction, SIGNAL(triggered()), this, SLOT(showNewFile()));

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
    connect(printTRextAction, SIGNAL(triggered()), this, SLOT(showPrintText()));


    //“打印图像”动作
    printImageAction = new QAction(QIcon("printImage.png"), tr("打印图像"), this);
    printImageAction->setStatusTip(tr("打印一幅图像"));
    connect(printImageAction, SIGNAL(triggered()), this, SLOT(showPrintImage()));

    //“放大”动作
    zoomInAction = new QAction(QIcon("zoomin.png"), tr("放大"), this);
    zoomInAction->setStatusTip(tr("放大一张照片"));
    connect(zoomInAction, SIGNAL(triggered()), this, SLOT(showZoomIn()));

    //“缩小”动作
    zoomOutAction = new QAction(QIcon("zoomout.png"), tr("缩小"), this);
    zoomOutAction->setStatusTip(tr("缩小一张照片"));
    connect(zoomOutAction, SIGNAL(triggered()), this, SLOT(showZoomOut()));

    //实现图像旋转的动作
    //90
    rotate90Action = new QAction(QIcon("rotate90.png"), tr("旋转90"), this);
    rotate90Action->setStatusTip(tr("将一幅图像旋转90度"));
    connect(rotate90Action, SIGNAL(triggered()), this, SLOT(showRotate90()));
    //180
    rotate180Action = new QAction(QIcon("rotate180.png"), tr("旋转180"), this);
    rotate180Action->setStatusTip(tr("将一幅图像旋转180度"));
    connect(rotate180Action, SIGNAL(triggered()), this, SLOT(showRotate180()));
    //270
    rotate270Action = new QAction(QIcon("rotate270.png"), tr("旋转270"), this);
    rotate270Action->setStatusTip(tr("将一副图像旋转270度"));
    connect(rotate270Action, SIGNAL(triggered()), this, SLOT(showRotate270()));

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
    zoomMenu = menuBar()->addMenu(tr("编辑"));
    zoomMenu->addAction(copyAction);
    zoomMenu->addAction(cutAction);
    zoomMenu->addAction(pasteAction);
    zoomMenu->addAction(aboutAction);
    zoomMenu->addSeparator();
    zoomMenu->addAction(zoomInAction);
    zoomMenu->addAction(zoomOutAction);


    //旋转菜单
    rotateMenu = menuBar()->addMenu(tr("旋转"));
    rotateMenu->addAction(rotate90Action);
    rotateMenu->addAction(rotate180Action);
    rotateMenu->addAction(rotate270Action);

    //镜像菜单
    mirrorMenu = menuBar()->addMenu(tr("镜像"));
    mirrorMenu->addAction(mirrorVerticalAction);
    mirrorMenu->addAction(mirrorHorizontalAction);
}


void ImgProcessor::createToolBars()
{
    //文件工具条
    fileTool = addToolBar("File");
    fileTool->addAction(openFileAction);
    fileTool->addAction(NewFileAction);
    fileTool->addAction(printTRextAction);
    fileTool->addAction(printImageAction);

    //编辑工具条
    zoomTool = addToolBar("Edit");
    zoomTool->addAction(copyAction);
    zoomTool->addAction(cutAction);
    zoomTool->addAction(pasteAction);
    zoomTool->addSeparator();
    zoomTool->addAction(zoomInAction);
    zoomTool->addAction(zoomOutAction);

    //旋转工具条
    rotateTool = addToolBar("rotate");
    rotateTool->addAction(rotate90Action);
    rotateTool->addAction(rotate180Action);
    rotateTool->addAction(rotate270Action);

    //撤销和重做工具条
    doToolBar = addToolBar("doEdit");
    doToolBar->addAction(undoAction);
    doToolBar->addAction(redoAction);

    //字体工具条
    fontToolBar = addToolBar("font");
    fontToolBar->addWidget(fontLabel);
    fontToolBar->addWidget(fontLabel2);
    fontToolBar->addWidget(sizeComboBox);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(boldBtn);
    fontToolBar->addWidget(italicBtn);
    fontToolBar->addWidget(underlineBtn);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(colorBtn);
}

void ImgProcessor::showNewFile()
{
    ImgProcessor *newImgProcessor = new ImgProcessor;
    newImgProcessor->show();
}

void ImgProcessor::loadFile(QString filename)
{
    qDebug() << "file name :" << filename;
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream textStream(&file);
        while(!textStream.atEnd())
        {
            showWidget->text->append(textStream.readLine());
            qDebug() << "read line";
        }
    }
}

void ImgProcessor::showOpenFile()
{
    fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        if(showWidget->text->document()->isEmpty())
        {
            loadFile(fileName);
        }
        else
        {
            ImgProcessor *newImgProcessor = new ImgProcessor;
            newImgProcessor->show();
            newImgProcessor->loadFile(fileName);
        }
    }
}

void ImgProcessor::showPrintText()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);//创建一个QPrintDialog对象。
    if(printDialog.exec())
    {
        //获得QTextEdit 对象的文档
        QTextDocument *doc = showWidget->text->document();
        doc->print(&printer);
    }
}

void ImgProcessor::showPrintImage()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    if(printDialog.exec())
    {
        QPainter painter(&printer);
        QRect rect = painter.viewport();//获得QPainter 对象的视图矩形区域
        QSize size = img.size();
        //安装图片的比例大小重新设定视图矩形区域
        size.scale(rect.size(), Qt::KeepAspectRatio);
        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
        painter.setWindow(img.rect());
        painter.drawImage(0, 0, img);

    }
}

void ImgProcessor::showZoomIn()
{
    if(img.isNull())//有效判断
    {
        return;
    }
    QMatrix martix;//声明一个QMatrix类的实例
    martix.scale(2, 2); //该参数决定x方向和y方向的缩放比例
    img = img.transformed(martix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showZoomOut()
{
    if(img.isNull())
    {
        return ;
    }
    QMatrix matrix;
    matrix.scale(0.5, 0.5);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showRotate90()
{
    if(img.isNull())
    {
        return ;
    }
    QMatrix matrix;
    matrix.rotate(90);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showRotate180()
{
    if(img.isNull())
    {
        return ;
    }
    QMatrix matrix;
    matrix.rotate(180);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::showRotate270()
{
    if(img.isNull())
    {
        return ;
    }
    QMatrix matrix;
    matrix.rotate(270);
    img = img.transformed(matrix);
    showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
}

void ImgProcessor::ShowFontComboBox(QString comboStr)
{
    //设置字体
    QTextCharFormat fmt;//创建一个QTextCharFormat对象
    fmt.setFontFamily(comboStr);//选择的字体名称设置给QTextCharFormat对象
    mergeFormat(fmt);//将新的格式应用到光标选区内的字符。
}

void ImgProcessor::mergeFormat(QTextCharFormat format)
{
    //设置格式
    QTextCursor cursor = showWidget->text->textCursor();//获得编辑框中的光标

    if(!cursor.hasSelection())
    {
        cursor.select(QTextCursor::WordUnderCursor);
    }
    cursor.mergeCharFormat(format);
    showWidget->text->mergeCurrentCharFormat(format);
}

void ImgProcessor::ShowSizeSpinBox(QString spinValue)
{
    //设置字号
    qDebug() << spinValue << "--" << spinValue.toFloat();
    QTextCharFormat fmt;
    fmt.setFontPointSize(spinValue.toFloat());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImgProcessor::ShowBoldBtn()
{
    //设置选中的字体加粗
    QTextCharFormat fmt;
    fmt.setFontWeight(boldBtn->isChecked() ? QFont::Bold : QFont::Normal);
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImgProcessor::ShowItalicBtn()
{
    //设置字体斜体
    QTextCharFormat fmt;
    fmt.setFontItalic(italicBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImgProcessor::ShowUnderlineBtn()
{
    //设置文字下划线
    QTextCharFormat fmt;
    fmt.setFontUnderline(underlineBtn->isChecked());
    showWidget->text->mergeCurrentCharFormat(fmt);
}

void ImgProcessor::ShowColorBtn()
{
    //设置颜色
    QColor color = QColorDialog::getColor(Qt::red, this);
    if(color.isValid())
    {
        QTextCharFormat fmt;
        fmt.setForeground(color);
        showWidget->text->mergeCurrentCharFormat(fmt);
    }
}

void ImgProcessor::ShowCurrentFormatChanged(const QTextCharFormat &fmt)
{
    fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
    sizeComboBox->setCurrentIndex(sizeComboBox->findText(QString::number(fmt.fontPointSize())));
    boldBtn->setChecked(fmt.font().bold());
    italicBtn->setChecked(fmt.fontItalic());
    underlineBtn->setChecked(fmt.fontUnderline());
}
