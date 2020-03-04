#ifndef PALETE_H
#define PALETE_H

#include <QDialog>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>

class Palete : public QDialog
{
    Q_OBJECT

public:
    Palete(QWidget *parent = nullptr);
    ~Palete();

    //完成窗体左半部分颜色选择区域
    void createCtrlFrame();
    //完成窗体右半部分的创建
    void createContentFrame();
    //完成颜色下拉列表框中插入颜色的创建
    void fillColorList(QComboBox *);

private slots:
    void showWindow();
    void showWindowText();
    void showButton();
    void showButtonText();
    void showBase();

private:
    //颜色选择面板
    QFrame *ctrlFrame;

    QLabel *windowLabel;
    QComboBox *windowComboBox;
    QLabel *windowTextLabel;
    QComboBox *windowTextComboBox;
    QLabel *buttonLabel;
    QComboBox *buttonComboBox;
    QLabel *buttonTextLabel;
    QComboBox *buttonTextComboBox;
    QLabel *baseLabel;
    QComboBox *baseTextComboBox;

    QFrame *contentFrame;
    QLabel *label1;
    QComboBox *comboBox1;
    QLabel *label2;
    QLineEdit *textEdit2;
    QTextEdit *textEdit;
    QPushButton *OkBtn;
    QPushButton *CancelBtn;
};
#endif // PALETE_H
