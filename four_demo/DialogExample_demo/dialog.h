#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>

#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QFrame>
#include "inputdlg.h"
#include "msgboxdlg.h"


class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    //标准文件对话框槽函数
    void showFile();
    //标准颜色对话框槽函数
    void showColor();
    //标准字体对话框槽函数
    void showFont();
    //标准输入对话框槽函数
    void showInputDlg();
    //各种消息对话框槽函数
    void showMsgDlg();
    //自定义消息对话框槽函数
    void showCustomDlg();

private:
    //主体布局
    QGridLayout *mainLayout;

    //标准文件对话框
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;

    //标准颜色对话框
    QPushButton *colorBtn;
    QFrame *colorFrame;

    //标准字体对话框
    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;

    //标准输入对话框
    InputDlg *inputDlg;
    QPushButton *inputBtn;

    //各种消息对话框
    QPushButton *MsgBtn;
    MsgBoxDlg *msgDlg;

    //自定义消息框
    QPushButton *CustomBtn;
    QLabel *label;


};
#endif // DIALOG_H
