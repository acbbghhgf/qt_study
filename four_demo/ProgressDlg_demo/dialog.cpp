#include "dialog.h"
#include <QProgressDialog>
#include <QFont>
#include <QDebug>
#include <QThread>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QFont font("ZYSong18030", 12);
    setFont(font);
    setWindowTitle(tr("Progress"));

    FileNum = new QLabel(tr("文件数目："));
    FileNumLineEdit = new QLineEdit;
    FileNumLineEdit->setText(tr("10000"));
    ProgressType = new QLabel(tr("显示类型："));
    comBox = new QComboBox;
    comBox->addItem(tr("progressBar"));
    comBox->addItem(tr("ProgressDialog"));
    progressBar = new QProgressBar;
    startBtn = new QPushButton(tr("开始"));

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(FileNum, 0, 0);
    mainLayout->addWidget(FileNumLineEdit, 0 ,1);
    mainLayout->addWidget(ProgressType, 1, 0);
    mainLayout->addWidget(comBox, 1, 1);
    mainLayout->addWidget(progressBar, 2, 0, 1, 2);
    mainLayout->addWidget(startBtn, 3, 1);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);

    connect(startBtn, SIGNAL(clicked()), this, SLOT(startProgress()));

}

Dialog::~Dialog()
{
}

void Dialog::startProgress()
{
    bool ok;
    int num = FileNumLineEdit->text().toInt(&ok);
    if(comBox->currentIndex() == 0)
    {
        progressBar->setRange(0, num);
        for(int i = 0; i <= num; ++i)
        {
            progressBar->setValue(i);
        }
    }
    else if(comBox->currentIndex() == 1)
    {
        //创建一个进度对话框
        QProgressDialog *progressDialog = new QProgressDialog(this);

        qDebug() << "QProgressDialog display" << num;
        QFont font("ZYSong1830", 12);
        progressDialog->setFont(font);
        progressDialog->setWindowModality(Qt::WindowModal);
        progressDialog->setMinimumDuration(5);
        progressDialog->setWindowTitle(tr("please Wait!"));
        progressDialog->setLabelText(tr("Copying..."));
        progressDialog->setCancelButtonText(tr("Cancel"));
        progressDialog->setRange(0, num);
//        progressDialog->show();
        progressDialog->update();
        for(int i = 0; i < num + 1; i++)
        {
            QThread::sleep(1);
            progressDialog->setValue(i);
            progressDialog->update();
            if(progressDialog->wasCanceled())
            {
                return ;
            }
        }
    }
}
