#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "paintarea.h"
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QGradient>

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

private:
    PaintArea *paintarea;//绘图窗口
    QLabel *shapeLabel;
    QComboBox *shapeCombox;
    QLabel *penWidthLabel;
    QSpinBox *penWidthSpinbox;
    QLabel *penColorLabel;
    QSpinBox *penColorSpinbox;
    QFrame *penColorFrame;
    QPushButton *pencolorbtn;
    QLabel *penstylelabel;
    QComboBox *penstylecombox;
    QLabel *pencaplabel;
    QComboBox *pencapcombox;
    QLabel *penjoinlabel;
    QComboBox *penjoincombox;
    QLabel *fillrulelabel;
    QComboBox *fillrulecombox;
    QLabel *spreadlabel;
    QComboBox *spreadcombox;

    QGradient::Spread spread;
    QLabel *brushstylelabel;
    QComboBox *brushstylecombox;
    QLabel *brushcolorlabel;
    QFrame *brushColorFrame;
    QPushButton *brushColorbtn;
    QGridLayout *rightLayout;

protected slots:
    void showshape(int);
    void showpenwidth(int);
    void showpencolor();
    void showpenstyle(int);
    void showpencap(int);
    void showpenjoin(int);
    void showspreadstyle();
    void showfillrule();
    void showbrushcolor();
    void showbrush(int);

};
#endif // MAINWIDGET_H
