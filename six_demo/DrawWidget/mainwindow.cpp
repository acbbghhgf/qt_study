#include "mainwindow.h"
#include <QToolBar>
#include <QColor>
#include <QColorDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    drawWidget = new Drawwidget;
    setCentralWidget(drawWidget);//新建的DrawWidget作为主窗口的中央。
    createToolBar();//工具栏实现

    setMinimumSize(600, 400);
    showStyle();//初始化线型，设置空间当前值作为初始值.

    drawWidget->setWidth(widthSpinBox->value());
    drawWidget->setColor(Qt::black);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createToolBar()
{
    QToolBar *toolbar = addToolBar("Tool");
    stylelabel = new QLabel(tr("线型风格："));
    styleComboBox = new QComboBox;
    styleComboBox->addItem(tr("SolidLine"), static_cast<int>(Qt::SolidLine));
    styleComboBox->addItem(tr("DashLine"), static_cast<int>(Qt::DashLine));
    styleComboBox->addItem(tr("DotLine"), static_cast<int>(Qt::DotLine));
    styleComboBox->addItem(tr("DashDotLine"), static_cast<int>(Qt::DashDotLine));
    styleComboBox->addItem(tr("DashDotDotLine"), static_cast<int>(Qt::DashDotDotLine));
    connect(styleComboBox, SIGNAL(activated(int)), this, SLOT(showStyle()));
    widthLabel = new QLabel(tr("线宽："));
    widthSpinBox = new QSpinBox;
    connect(widthSpinBox, SIGNAL(valueChanged(int)), drawWidget, SLOT(setWidth(int)));

    colorBtn = new QToolButton;
    QPixmap pixmap(20, 20);
    pixmap.fill(Qt::black);
    colorBtn->setIcon(QIcon(pixmap));
    connect(colorBtn, SIGNAL(clicked()), this, SLOT(showColor()));
    clearBtn = new QToolButton;
    connect(clearBtn, SIGNAL(clicked()), drawWidget, SLOT(clear()));

    toolbar->addWidget(stylelabel);
    toolbar->addWidget(styleComboBox);
    toolbar->addWidget(widthLabel);
    toolbar->addWidget(widthSpinBox);
    toolbar->addWidget(colorBtn);
    toolbar->addWidget(clearBtn);

}

void MainWindow::showStyle()
{
    drawWidget->setStyle(styleComboBox->itemData(styleComboBox->currentIndex(), Qt::UserRole).toInt());
}

void MainWindow::showColor()
{
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::black), this);
    if(color.isValid())//有效颜色
    {
        drawWidget->setColor(color);
        QPixmap p(20, 20);
        p.fill(color);
        colorBtn->setIcon(QIcon(p));//更新按钮颜色
    }
}
