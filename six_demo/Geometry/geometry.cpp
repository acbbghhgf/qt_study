#include "geometry.h"

Geometry::Geometry(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Geometry"));

    xLabel = new QLabel(tr("x():"));
    xValue = new QLabel;
    yLabel = new QLabel(tr("y():"));
    yValue = new QLabel;

    frameLabel = new QLabel(tr("Frame:"));
    frameValue = new QLabel;
    posLabel = new QLabel(tr("pos():"));
    posValue = new QLabel;
    geometryLabel = new QLabel(tr("geometry():"));
    geometryValue = new QLabel;

    widthLabel = new QLabel(tr("width():"));
    widthValue = new QLabel;
    heightLabel = new QLabel(tr("height():"));
    heightValue = new QLabel;

    rectLabel = new QLabel(tr("rect():"));
    rectValue = new QLabel;
    sizeLabel = new QLabel(tr("size():"));
    sizeValue = new QLabel;

    //布局
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(xLabel, 0, 0);
    mainLayout->addWidget(xValue, 0, 1);
    mainLayout->addWidget(yLabel, 1, 0);
    mainLayout->addWidget(yValue, 1, 1);
    mainLayout->addWidget(frameLabel, 2, 0);
    mainLayout->addWidget(frameValue, 2, 1);
    mainLayout->addWidget(posLabel, 3, 0);
    mainLayout->addWidget(posValue, 3, 1);
    mainLayout->addWidget(geometryLabel, 4, 0);
    mainLayout->addWidget(geometryValue, 4, 1);
    mainLayout->addWidget(widthLabel, 5, 0);
    mainLayout->addWidget(widthValue, 5, 1);
    mainLayout->addWidget(heightLabel, 6, 0);
    mainLayout->addWidget(heightValue, 6, 1);
    mainLayout->addWidget(rectLabel, 7, 0);
    mainLayout->addWidget(rectValue, 7, 1);
    mainLayout->addWidget(sizeLabel, 8, 0);
    mainLayout->addWidget(sizeValue, 8, 1);

    updateLabel();
}

Geometry::~Geometry()
{
}

void Geometry::updateLabel()
{
    QString xstr;
    xValue->setText(xstr.setNum(x()));
    QString ystr;
    yValue->setText(ystr.setNum(y()));

    QString framestr;
    framestr = QString("%1 , %2, %3, %4").arg(frameGeometry().x()).arg(frameGeometry().y())\
            .arg(frameGeometry().width()).arg(frameGeometry().height());
    frameValue->setText(framestr);

    QString posstr;
    posstr = QString("(%1, %2)").arg(pos().x()).arg(pos().y());
    posValue->setText(posstr);

    QString geostr;
    geostr = QString("%1, %2, %3, %4").arg(geometry().x()).arg(geometry().y()).arg(geometry().width())\
            .arg(geometry().height());
    geometryValue->setText(geostr);

    QString wstr, hstr;
    widthValue->setText(wstr.setNum(width()));
    heightValue->setText(hstr.setNum(height()));

    QString rectstr;
    rectstr = QString("%1, %2, %3, %4").arg(rect().x()).arg(rect().y()).arg(rect().width()).arg(rect().height());
    rectValue->setText(rectstr);

    QString sizestr;
    sizestr = QString("%1, %2").arg(size().width()).arg(size().height());
    sizeValue->setText(sizestr);

}

void Geometry::moveEvent(QMoveEvent *)
{
    updateLabel();
}

void Geometry::resizeEvent(QResizeEvent *)
{
    updateLabel();
}
