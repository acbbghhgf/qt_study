#include "palete.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

Palete::Palete(QWidget *parent)
    : QDialog(parent)
{
    createCtrlFrame();
    createContentFrame();
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(ctrlFrame);
    mainLayout->addWidget(contentFrame);
}

Palete::~Palete()
{
}

void Palete::createCtrlFrame()
{
    //颜色选择面板
    ctrlFrame = new QFrame;
    windowLabel = new QLabel(tr("QPalette::Window:"));
    windowComboBox = new QComboBox;
    fillColorList(windowComboBox);
    connect(windowComboBox, SIGNAL(activated(int)), this, SLOT(showWindow()));

    windowTextLabel = new QLabel(tr("QPalette::WindowText:"));
    windowTextComboBox = new QComboBox;
    fillColorList(windowTextComboBox);
    connect(windowTextComboBox, SIGNAL(activated(int)), this, SLOT(showWindowText()));

    buttonLabel = new QLabel(tr("QPalette::button:"));
    buttonComboBox = new QComboBox;
    fillColorList(buttonComboBox);
    connect(buttonComboBox, SIGNAL(activated(int)), this, SLOT(showButton()));

    buttonTextLabel = new QLabel(tr("QPalette::buttonText:"));
    buttonTextComboBox = new QComboBox;
    fillColorList(buttonTextComboBox);
    connect(buttonTextComboBox, SIGNAL(activated(int)), this, SLOT(showButtonText()));

    baseLabel = new QLabel(tr("QPalette::Base:"));
    baseTextComboBox = new QComboBox;
    fillColorList(baseTextComboBox);
    connect(baseTextComboBox, SIGNAL(activated(int)), this, SLOT(showBase()));

    QGridLayout *mainLayout = new QGridLayout(ctrlFrame);
    mainLayout->setSpacing(20);
    mainLayout->addWidget(windowLabel, 0, 0);
    mainLayout->addWidget(windowComboBox, 0, 1);
    mainLayout->addWidget(windowTextLabel, 1, 0);
    mainLayout->addWidget(windowTextComboBox, 1, 1);
    mainLayout->addWidget(buttonLabel, 2, 0);
    mainLayout->addWidget(buttonComboBox, 2, 1);
    mainLayout->addWidget(buttonTextLabel, 3, 0);
    mainLayout->addWidget(buttonTextComboBox, 3, 1);
    mainLayout->addWidget(baseLabel, 4, 0);
    mainLayout->addWidget(baseTextComboBox, 4, 1);

}

void Palete::createContentFrame()
{
    contentFrame = new QFrame;
    label1 = new QLabel(tr("请选择一个值："));
    comboBox1 = new QComboBox;
    label2 = new QLabel(tr("请输入字符串："));
    textEdit2 = new QLineEdit;
    textEdit = new QTextEdit;
    QGridLayout *TopLayout = new QGridLayout;
    TopLayout->addWidget(label1, 0, 0);
    TopLayout->addWidget(comboBox1, 0, 1);
    TopLayout->addWidget(label2, 1, 0);
    TopLayout->addWidget(textEdit2, 1, 1);
    TopLayout->addWidget(textEdit, 2, 0, 1, 2);

    OkBtn = new QPushButton(tr("确认"));
    CancelBtn = new QPushButton(tr("取消"));

    QHBoxLayout *BottomLayout = new QHBoxLayout;
    BottomLayout->addStretch(1);
    BottomLayout->addWidget(OkBtn);
    BottomLayout->addWidget(CancelBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout(contentFrame);
    mainLayout->addLayout(TopLayout);
    mainLayout->addLayout(BottomLayout);
}

void Palete::showWindow()
{
    //获取当前选择的颜色值
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[windowComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Window, color);
    //把修改后的调色板信息应用到contentframe窗体中，更新显示
    contentFrame->setPalette(p);
    contentFrame->update();
}

void Palete::showWindowText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = colorList[windowTextComboBox->currentIndex()];
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::WindowText, color);
    contentFrame->setPalette(p);
    contentFrame->update();
}

void Palete::showButton()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[buttonComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Button, color);
    contentFrame->setPalette(p);
    contentFrame->update();
}

void Palete::showButtonText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[buttonTextComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::ButtonText, color);
    contentFrame->setPalette(p);
    contentFrame->update();
}

void Palete::showBase()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[baseTextComboBox->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Base, color);
    contentFrame->setPalette(p);
    contentFrame->update();
}

void Palete::fillColorList(QComboBox *comboBox)
{
    QStringList colorlist = QColor::colorNames();
    QString color;
    foreach(color, colorlist)
    {
        QPixmap pix(QSize(70, 20));
        pix.fill(QColor(color));
        comboBox->addItem(QIcon(pix), NULL);
        comboBox->setIconSize(QSize(70, 20));
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    }
}
