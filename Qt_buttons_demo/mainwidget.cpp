#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QStandardItemModel>

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);

    //--------------------------------------------------视图与模型绑定，模型必须使用new创建，否则视图不能随模型改变而改变。
//    QStandardItemModel model(4, 2); 错误，没有使用new创建。
    QStandardItemModel *model = new QStandardItemModel(4, 2); //正确，应该使用new创建model。
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Label"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantity"));
    ui->tableView->setModel(model);
    for(int row = 0; row <4 ; ++row)
    {
        for(int column = 0; column < 2; ++column)
        {
            QModelIndex index = model->index(row, column, QModelIndex());
//            model->setData(index, QVariant((row + 1) *(column + 1)));
            model->setData(index, QVariant((row + column)));
        }
    }
}

mainWidget::~mainWidget()
{
    delete ui;
}
