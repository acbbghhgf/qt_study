#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>

class Geometry : public QDialog
{
    Q_OBJECT

public:
    Geometry(QWidget *parent = nullptr);
    ~Geometry();
    void updateLabel();

protected:
    void moveEvent(QMoveEvent *);
    void resizeEvent(QResizeEvent *);

private:
    QLabel *xLabel;
    QLabel *xValue;
    QLabel *yLabel;
    QLabel *yValue;
    QLabel *posLabel;
    QLabel *posValue;
    QLabel *frameLabel;
    QLabel *frameValue;
    QLabel *geometryLabel;
    QLabel *geometryValue;
    QLabel *widthLabel;
    QLabel *widthValue;
    QLabel *heightLabel;
    QLabel *heightValue;
    QLabel *rectLabel;
    QLabel *rectValue;
    QLabel *sizeLabel;
    QLabel *sizeValue;
    QGridLayout *mainLayout;

};
#endif // GEOMETRY_H
