#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "drawwidget.h"
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QToolButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createToolBar();

public slots:
    void showColor();
    void showStyle();

private:
    Drawwidget *drawWidget;
    QLabel *stylelabel;
    QComboBox *styleComboBox;
    QLabel *widthLabel;
    QSpinBox *widthSpinBox;
    QToolButton *colorBtn;
    QToolButton *clearBtn;

};
#endif // MAINWINDOW_H
