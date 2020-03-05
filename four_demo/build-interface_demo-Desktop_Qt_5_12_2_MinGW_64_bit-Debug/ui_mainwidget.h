/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWidget
{
public:
    QPushButton *pushButton_4;
    QLabel *label;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QProgressBar *progressBar;
    QPushButton *pushButton_12;
    QTextEdit *textEdit;
    QProgressBar *progressBar_2;
    QLabel *label_2;
    QProgressBar *progressBar_3;
    QPushButton *pushButton_5;
    QLabel *label_3;
    QProgressBar *progressBar_4;
    QPushButton *pushButton_6;
    QLabel *label_4;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;

    void setupUi(QWidget *mainWidget)
    {
        if (mainWidget->objectName().isEmpty())
            mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->resize(1024, 600);
        pushButton_4 = new QPushButton(mainWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(80, 120, 151, 41));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{ border: 0px solid;background-color:rgb(0, 185, 122);color:#FFFFFF;border-radius: 20px;}QPushButton:hover{background-color:rgb(255, 0, 0);}\n"
""));
        label = new QLabel(mainWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 40, 141, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bahnschrift"));
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("font-size:30px;color:rgb(133, 139, 133)"));
        pushButton_9 = new QPushButton(mainWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(900, 530, 81, 41));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_9->setFont(font2);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton{ border: 0px solid;background-color:rgb(0, 85, 0);color:#FFFFFF;border-radius: 20px;}QPushButton:hover{background-color:rgb(255, 0, 0);}\n"
""));
        pushButton_10 = new QPushButton(mainWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(130, 440, 101, 51));
        pushButton_10->setFont(font2);
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton{ border: 0px solid;background-color:rgb(0, 170, 0);color:#FFFFFF;border-radius: 20px;}QPushButton:hover{background-color:rgb(255, 0, 0);}\n"
""));
        pushButton_11 = new QPushButton(mainWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(370, 440, 101, 51));
        pushButton_11->setFont(font2);
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton{ border: 0px solid;background-color:rgb(0, 170, 0);color:#FFFFFF;border-radius: 20px;}QPushButton:hover{background-color:rgb(255, 0, 0);}\n"
""));
        progressBar = new QProgressBar(mainWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(70, 520, 521, 23));
        progressBar->setValue(0);
        pushButton_12 = new QPushButton(mainWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(790, 530, 81, 41));
        pushButton_12->setFont(font2);
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton{ border: 0px solid;background-color:rgb(0, 85, 0);color:#FFFFFF;border-radius: 20px;}QPushButton:hover{background-color:rgb(255, 0, 0);}\n"
""));
        textEdit = new QTextEdit(mainWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(570, 110, 381, 281));
        progressBar_2 = new QProgressBar(mainWidget);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(240, 130, 211, 20));
        progressBar_2->setValue(0);
        label_2 = new QLabel(mainWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(470, 120, 71, 41));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("font-size:14px;color:rgb(255, 55, 200)"));
        progressBar_3 = new QProgressBar(mainWidget);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setGeometry(QRect(240, 220, 211, 20));
        progressBar_3->setValue(0);
        pushButton_5 = new QPushButton(mainWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(80, 210, 151, 41));
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton{ border: 0px solid;background-color:rgb(0, 185, 122);color:#FFFFFF;border-radius: 20px;}QPushButton:hover{background-color:rgb(255, 0, 0);}\n"
""));
        label_3 = new QLabel(mainWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(470, 210, 71, 41));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("font-size:14px;color:rgb(255, 55, 200)"));
        progressBar_4 = new QProgressBar(mainWidget);
        progressBar_4->setObjectName(QString::fromUtf8("progressBar_4"));
        progressBar_4->setGeometry(QRect(240, 310, 211, 20));
        progressBar_4->setValue(0);
        pushButton_6 = new QPushButton(mainWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(80, 300, 151, 41));
        pushButton_6->setFont(font);
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton{ border: 0px solid;background-color:rgb(0, 185, 122);color:#FFFFFF;border-radius: 20px;}QPushButton:hover{background-color:rgb(255, 0, 0);}\n"
""));
        label_4 = new QLabel(mainWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(470, 300, 71, 41));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("font-size:14px;color:rgb(255, 55, 200)"));
        pushButton_13 = new QPushButton(mainWidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(780, 400, 61, 21));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_13->setFont(font3);
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton{ border: 0px solid;background-color:rgb(85, 85, 85);color:#FFFFFF;border-radius: 20px;}QPushButton:hover{background-color:rgb(255, 0, 0);}\n"
""));
        pushButton_14 = new QPushButton(mainWidget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(880, 400, 61, 21));
        pushButton_14->setFont(font3);
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton{ border: 0px solid;background-color:rgb(85, 85, 85);color:#FFFFFF;border-radius: 20px;}QPushButton:hover{background-color:rgb(255, 0, 0);}\n"
""));

        retranslateUi(mainWidget);

        QMetaObject::connectSlotsByName(mainWidget);
    } // setupUi

    void retranslateUi(QWidget *mainWidget)
    {
        mainWidget->setWindowTitle(QApplication::translate("mainWidget", "mainWidget", nullptr));
        pushButton_4->setText(QApplication::translate("mainWidget", "\345\205\211\350\267\257\351\200\232\350\256\257\346\265\213\350\257\225", nullptr));
        label->setText(QApplication::translate("mainWidget", "\351\200\232\350\256\257\346\265\213\350\257\225", nullptr));
        pushButton_9->setText(QApplication::translate("mainWidget", "\350\277\224\345\233\236", nullptr));
        pushButton_10->setText(QApplication::translate("mainWidget", "\345\274\200\345\247\213", nullptr));
        pushButton_11->setText(QApplication::translate("mainWidget", "\345\201\234\346\255\242", nullptr));
        pushButton_12->setText(QApplication::translate("mainWidget", "\350\257\246\347\273\206", nullptr));
        label_2->setText(QApplication::translate("mainWidget", "\346\234\252\345\274\200\345\247\213", nullptr));
        pushButton_5->setText(QApplication::translate("mainWidget", "\346\226\207\346\234\254\346\225\260\346\215\256\344\274\240\350\276\223\346\265\213\350\257\225", nullptr));
        label_3->setText(QApplication::translate("mainWidget", "\346\234\252\345\274\200\345\247\213", nullptr));
        pushButton_6->setText(QApplication::translate("mainWidget", "\345\233\276\347\211\207\346\225\260\346\215\256\344\274\240\350\276\223\346\265\213\350\257\225", nullptr));
        label_4->setText(QApplication::translate("mainWidget", "\346\234\252\345\274\200\345\247\213", nullptr));
        pushButton_13->setText(QApplication::translate("mainWidget", "\344\277\235\345\255\230", nullptr));
        pushButton_14->setText(QApplication::translate("mainWidget", "\346\211\223\345\215\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWidget: public Ui_mainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
