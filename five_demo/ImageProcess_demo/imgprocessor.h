#ifndef IMGPROCESSOR_H
#define IMGPROCESSOR_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QComboBox>
#include <QSpinBox>
#include <QToolBar>
#include <QFontComboBox>
#include <QToolButton>
#include <QTextCharFormat>
#include "showwidget.h"
#include <QDebug>

class ImgProcessor : public QMainWindow
{
    Q_OBJECT

public:
    ImgProcessor(QWidget *parent = nullptr);
    ~ImgProcessor();

    void createActions();
    void createMenus();
    void createToolBars();
    void loadFile(QString filename);
    void mergeFormat(QTextCharFormat);

private slots:
    void showNewFile();//新建文件
    void showOpenFile();//打开文件
    void showPrintText();//打印文本文件
    void showPrintImage();//打印图片
    void showZoomIn();//放大
    void showZoomOut();//缩小
    void showRotate90(); //旋转90
    void showRotate180();
    void showRotate270();

protected slots:
    void ShowFontComboBox(QString comboStr);
    void ShowSizeSpinBox(QString spinValue);
    void ShowBoldBtn();
    void ShowItalicBtn();
    void ShowUnderlineBtn();
    void ShowColorBtn();
    void ShowCurrentFormatChanged(const QTextCharFormat &fmt);

private:
    QMenu *fileMenu;
    QMenu *zoomMenu;
    QMenu *rotateMenu;
    QMenu *mirrorMenu;
    QImage img;
    QString fileName;

    ShowWidget *showWidget; //文件菜单项
    QAction *openFileAction;
    QAction *NewFileAction;
    QAction *printTRextAction;
    QAction *printImageAction;
    QAction *exitAction;
    QAction *copyAction;    //编辑菜单项
    QAction *cutAction;
    QAction *pasteAction;
    QAction *aboutAction;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *rotate90Action;    //旋转菜单项
    QAction *rotate180Action;
    QAction *rotate270Action;
    QAction *mirrorVerticalAction;  //镜像菜单项
    QAction *mirrorHorizontalAction;
    QAction *undoAction;
    QAction *redoAction;
    QToolBar *fileTool; //工具栏
    QToolBar *zoomTool;
    QToolBar *rotateTool;
    QToolBar *mirrorTool;
    QToolBar *doToolBar;

    QLabel *fontLabel;
    QFontComboBox *fontComboBox;
    QLabel *fontLabel2;
    QComboBox *sizeComboBox;
    QToolButton *boldBtn;
    QToolButton *italicBtn;
    QToolButton *underlineBtn;
    QToolButton *colorBtn;
    QToolBar *fontToolBar;
};
#endif // IMGPROCESSOR_H
