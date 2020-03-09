#include "mainwidget.h"
#include <QColorDialog>
#include <QLinearGradient>

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    paintarea = new PaintArea;

    shapeLabel = new QLabel(tr("形状："));
    //形状选择下拉框
    shapeCombox = new QComboBox;
    shapeCombox->addItem(tr("Line"), PaintArea::Line);
    shapeCombox->addItem(tr("Rectangle"), PaintArea::Rectangle);
    shapeCombox->addItem(tr("RoundedRect"), PaintArea::RoundRect);
    shapeCombox->addItem(tr("Ellipse"), PaintArea::Ellipse);
    shapeCombox->addItem(tr("Polygon"), PaintArea::Polygon);
    shapeCombox->addItem(tr("Polyline"), PaintArea::Polyline);
    shapeCombox->addItem(tr("Points"), PaintArea::Points);
    shapeCombox->addItem(tr("Arc"), PaintArea::Arc);
    shapeCombox->addItem(tr("Path"), PaintArea::Path);
    shapeCombox->addItem(tr("Text"), PaintArea::Text);
    shapeCombox->addItem(tr("Pixmap"), PaintArea::Pixmap);
    connect(shapeCombox, SIGNAL(activated(int)), this, SLOT(showshape(int)));

    //画笔颜色选择控件
    penColorLabel = new QLabel(tr("画笔颜色："));
    penColorFrame = new QFrame;
    penColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    penColorFrame->setAutoFillBackground(true);
    penColorFrame->setPalette(QPalette(Qt::blue));
    pencolorbtn = new QPushButton(tr("更改"));
    connect(pencolorbtn, SIGNAL(clicked()), this, SLOT(showpencolor()));

    //画笔线宽选择控件
    penWidthLabel = new QLabel(tr("画笔线宽："));
    penWidthSpinbox = new QSpinBox;
    penWidthSpinbox->setRange(0, 20);
    connect(penWidthSpinbox, SIGNAL(valueChanged(int)), this, SLOT(showpenwidth(int)));

    //画笔风格
    penstylelabel = new QLabel(tr("画笔风格："));
    penstylecombox = new QComboBox;
    penstylecombox->addItem(tr("solidline"), static_cast<int>(Qt::SolidLine));
    penstylecombox->addItem(tr("dashline"), static_cast<int>(Qt::DashLine));
    penstylecombox->addItem(tr("dotline"), static_cast<int>(Qt::DotLine));
    penstylecombox->addItem(tr("dashdotline"), static_cast<int>(Qt::DashDotLine));
    penstylecombox->addItem(tr("customdashline"), static_cast<int>(Qt::CustomDashLine));
    connect(penstylecombox, SIGNAL(activated(int)), this, SLOT(showpenstyle(int)));

    //画笔顶帽风格下拉列表
    pencaplabel = new QLabel(tr("画笔顶帽："));
    pencapcombox = new QComboBox;
    pencapcombox->addItem(tr("squarecap"), Qt::SquareCap);
    pencapcombox->addItem(tr("flatcap"), Qt::FlatCap);
    pencapcombox->addItem(tr("roundcap"), Qt::RoundCap);
    connect(pencapcombox, SIGNAL(activated(int)), this, SLOT(showpencap(int)));

    //画笔连接点风格下拉列表
    penjoinlabel = new QLabel(tr("画笔连接点："));
    penjoincombox = new QComboBox;
    penjoincombox->addItem(tr("beveljoin"), Qt::BevelJoin);
    penjoincombox->addItem(tr("miterjoin"), Qt::MiterJoin);
    penjoincombox->addItem(tr("roundjoin"), Qt::RoundJoin);
    connect(penjoincombox, SIGNAL(activated(int)), this, SLOT(showpenjoin(int)));

    //填充模式
    fillrulelabel = new QLabel(tr("填充模式："));
    fillrulecombox = new QComboBox;
    fillrulecombox->addItem(tr("odd even"), Qt::OddEvenFill);
    fillrulecombox->addItem(tr("winding"), Qt::WindingFill);
    connect(fillrulecombox, SIGNAL(activated(int)), this, SLOT(showfillrule()));

    //铺展效果
    spreadlabel = new QLabel(tr("铺展效果："));
    spreadcombox = new QComboBox;
    spreadcombox->addItem(tr("padspread"), QGradient::PadSpread);
    spreadcombox->addItem(tr("repeatspread"), QGradient::RepeatSpread);
    spreadcombox->addItem(tr("reflectspread"), QGradient::ReflectSpread);
    connect(spreadcombox, SIGNAL(activated(int)), this, SLOT(showspreadstyle()));

    //画刷颜色
    brushcolorlabel = new QLabel(tr("画刷颜色："));
    brushColorFrame = new QFrame;
    brushColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    brushColorFrame->setAutoFillBackground(true);
    brushColorFrame->setPalette(QPalette(Qt::green));
    brushColorbtn = new QPushButton(tr("更改"));
    connect(brushColorbtn, SIGNAL(clicked()), this, SLOT(showbrushcolor()));

    //画刷风格
    brushstylelabel = new QLabel(tr("画刷风格："));
    brushstylecombox = new QComboBox;
    brushstylecombox->addItem(tr("SoldPattern"), static_cast<int>(Qt::SolidPattern));
    brushstylecombox->addItem(tr("dense1pattern"), static_cast<int>(Qt::Dense1Pattern));
    brushstylecombox->addItem(tr("dense2pattern"), static_cast<int>(Qt::Dense2Pattern));
    brushstylecombox->addItem(tr("dense3pattern"), static_cast<int>(Qt::Dense3Pattern));
    brushstylecombox->addItem(tr("dense4pattern"), static_cast<int>(Qt::Dense4Pattern));
    brushstylecombox->addItem(tr("dense5pattern"), static_cast<int>(Qt::Dense5Pattern));
    brushstylecombox->addItem(tr("dense6pattern"), static_cast<int>(Qt::Dense6Pattern));
    brushstylecombox->addItem(tr("dense7pattern"), static_cast<int>(Qt::Dense7Pattern));
    brushstylecombox->addItem(tr("horpattern"), static_cast<int>(Qt::HorPattern));
    brushstylecombox->addItem(tr("verpattern"), static_cast<int>(Qt::VerPattern));
    brushstylecombox->addItem(tr("crosspattern"), static_cast<int>(Qt::CrossPattern));
    brushstylecombox->addItem(tr("bdiagpattern"), static_cast<int>(Qt::BDiagPattern));
    brushstylecombox->addItem(tr("fdiagpattern"), static_cast<int>(Qt::FDiagPattern));
    brushstylecombox->addItem(tr("diagcrosspattern"), static_cast<int>(Qt::DiagCrossPattern));
    brushstylecombox->addItem(tr("lineargradientpattern"), static_cast<int>(Qt::LinearGradientPattern));
    brushstylecombox->addItem(tr("ConicalGradientPattern"), static_cast<int>(Qt::ConicalGradientPattern));
    brushstylecombox->addItem(tr("RadialGradientPattern"), static_cast<int>(Qt::RadialGradientPattern));
    brushstylecombox->addItem(tr("TexturePattern"), static_cast<int>(Qt::TexturePattern));
    connect(brushstylecombox, SIGNAL(activated(int)), this, SLOT(showbrush(int)));

    //布局
    rightLayout = new QGridLayout;
    rightLayout->addWidget(shapeLabel, 0, 0);
    rightLayout->addWidget(shapeCombox, 0, 1);
    rightLayout->addWidget(pencaplabel, 1, 0);
    rightLayout->addWidget(penColorFrame, 1, 1);
    rightLayout->addWidget(pencolorbtn, 1, 2);
    rightLayout->addWidget(penWidthLabel, 2, 0);
    rightLayout->addWidget(penWidthSpinbox, 2, 1);
    rightLayout->addWidget(penstylelabel, 3, 0);
    rightLayout->addWidget(penstylecombox, 3, 1);
    rightLayout->addWidget(pencaplabel, 4, 0);
    rightLayout->addWidget(pencapcombox, 4, 1);
    rightLayout->addWidget(penjoinlabel, 5, 0);
    rightLayout->addWidget(penjoincombox, 5, 1);
    rightLayout->addWidget(fillrulelabel, 6, 0);
    rightLayout->addWidget(fillrulecombox, 6, 1);
    rightLayout->addWidget(spreadlabel, 7, 0);
    rightLayout->addWidget(spreadcombox, 7, 1);
    rightLayout->addWidget(brushcolorlabel, 8, 0);
    rightLayout->addWidget(brushColorFrame, 8, 1);
    rightLayout->addWidget(brushColorbtn, 8, 2);
    rightLayout->addWidget(brushstylelabel, 9, 0);
    rightLayout->addWidget(brushstylecombox, 9, 1);

    //整体布局
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(paintarea);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(paintarea, 1);
    mainLayout->setStretchFactor(rightLayout, 0);

    showshape(shapeCombox->currentIndex());
}

mainWidget::~mainWidget()
{
}


void mainWidget::showshape(int value)
{
    //设置PaintArea对象的形状参数
    PaintArea::Shape shape = PaintArea::Shape(shapeCombox->itemData(value, Qt::UserRole).toInt());
    paintarea->setShap(shape);
}

void mainWidget::showpencolor()
{
    //设置画笔颜色,调用颜色对话框进行选择
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
    penColorFrame->setPalette(QPalette(color));
    int value = penWidthSpinbox->value();
    //通过调用combox下的itemData返回当前显示的数据（枚举类型的序号）。
    Qt::PenStyle style = Qt::PenStyle(penstylecombox->itemData(penstylecombox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(pencapcombox->itemData(pencapcombox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penjoincombox->itemData(penjoincombox->currentIndex(), Qt::UserRole).toInt());

    paintarea->setPen(QPen(color, value, style, cap, join));//调用成员函数完成设置
}

void mainWidget::showpenwidth(int value)
{
    //获取当前的画笔颜色
    QColor color = penColorFrame->palette().color(QPalette::Window);
    //获取当前选择的各个参数。
    Qt::PenStyle style = Qt::PenStyle(penstylecombox->itemData(penstylecombox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(pencapcombox->itemData(pencapcombox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penjoincombox->itemData(penjoincombox->currentIndex(), Qt::UserRole).toInt());

    paintarea->setPen(QPen(color, value, style, cap, join));//调用接口更新
}

void mainWidget::showpenstyle(int stylevalue)
{
    //获取当前的画笔颜色
    QColor color = penColorFrame->palette().color(QPalette::Window);
    int value = penWidthSpinbox->value();
    //获取当前选择的各个参数。

    //使用改变的stylevalue参数获取style
    Qt::PenStyle style = Qt::PenStyle(penstylecombox->itemData(stylevalue, Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(pencapcombox->itemData(pencapcombox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penjoincombox->itemData(penjoincombox->currentIndex(), Qt::UserRole).toInt());

    paintarea->setPen(QPen(color, value, style, cap, join));//调用接口更新
}

void mainWidget::showpencap(int capvalue)
{
    //获取当前的画笔颜色
    QColor color = penColorFrame->palette().color(QPalette::Window);
    int value = penWidthSpinbox->value();
    //获取当前选择的各个参数。
    Qt::PenStyle style = Qt::PenStyle(penstylecombox->itemData(penstylecombox->currentIndex(), Qt::UserRole).toInt());
    //使用当前参数capvalue获取当前参数
    Qt::PenCapStyle cap = Qt::PenCapStyle(pencapcombox->itemData(capvalue, Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penjoincombox->itemData(penjoincombox->currentIndex(), Qt::UserRole).toInt());

    paintarea->setPen(QPen(color, value, style, cap, join));//调用接口更新
}

void mainWidget::showpenjoin(int joninvalue)
{
    //获取当前的画笔颜色
    QColor color = penColorFrame->palette().color(QPalette::Window);
    int value = penWidthSpinbox->value();
    //获取当前选择的各个参数。
    Qt::PenStyle style = Qt::PenStyle(penstylecombox->itemData(penstylecombox->currentIndex(), Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(pencapcombox->itemData(pencapcombox->currentIndex(), Qt::UserRole).toInt());

    Qt::PenJoinStyle join = Qt::PenJoinStyle(penjoincombox->itemData(joninvalue, Qt::UserRole).toInt());

    paintarea->setPen(QPen(color, value, style, cap, join));//调用接口更新
}

void mainWidget::showfillrule()
{
    Qt::FillRule rule = Qt::FillRule(fillrulecombox->itemData(fillrulecombox->currentIndex(), Qt::UserRole).toInt());
    //调用接口更新
    paintarea->setFillRule(rule);
}

void mainWidget::showspreadstyle()
{
    spread = QGradient::Spread(spreadcombox->itemData(spreadcombox->currentIndex(), Qt::UserRole).toInt());
}

void mainWidget::showbrushcolor()
{
    //获取颜色
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::blue));
    //更新颜色
    brushColorFrame->setPalette(QPalette(color));

    //调用画刷更新接口更新
    showbrush(brushstylecombox->currentIndex());
}

void mainWidget::showbrush(int value)
{
    //更新画刷属性
    //获取画刷颜色
    QColor color = brushColorFrame->palette().color(QPalette::Window);//获取当前画面的颜色

    Qt::BrushStyle style = Qt::BrushStyle(brushstylecombox->itemData(value, Qt::UserRole).toInt());
    //设置画刷风格
    if(style == Qt::LinearGradientPattern)//线性渐变风格
    {
        //创建线性渐变类对象需要两个参数，分别表示起止点位置
        QLinearGradient linearGradient(0, 0, 400, 400);
        linearGradient.setColorAt(0.0, Qt::white);
        linearGradient.setColorAt(0.2, color);
        linearGradient.setColorAt(1.0, Qt::black);
        linearGradient.setSpread(spread);
        paintarea->setBrush(linearGradient);
    }
    else if(style == Qt::RadialGradientPattern)//圆形渐变风格
    {
        //创建圆形渐变类，三个参数，圆心位置，半径值，焦点位置
        QRadialGradient radialGradient(200, 200, 150, 150, 100);
        radialGradient.setColorAt(0.0, Qt::white);
        radialGradient.setColorAt(0.2, color);
        radialGradient.setColorAt(1.0, Qt::black);
        radialGradient.setSpread(spread);
        paintarea->setBrush(radialGradient);
    }
    else if(style == Qt::ConicalGradientPattern)//锥形渐变
    {
        //创建锥形渐变类，两个参数-锥形定点位置和渐变分界线水平夹角
        QConicalGradient conicalgradient(200, 200, 30);
        conicalgradient.setColorAt(0.0, Qt::white);
        conicalgradient.setColorAt(0.2, color);
        conicalgradient.setColorAt(1.0, Qt::black);
        paintarea->setBrush(conicalgradient);
    }
    else if(style == Qt::TexturePattern)
    {
        paintarea->setBrush(QBrush(QPixmap("butterfly.png")));
    }
    else{
        //没有渐变风格的设置
        paintarea->setBrush(QBrush(color, style));
    }

}
