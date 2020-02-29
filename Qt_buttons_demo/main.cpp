#include "mainwidget.h"
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QTableView>
#include <QtSql/QSql>
#include <QTableView>
#include <QTableWidget>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlDriver>
#include <QStandardItem>
#include <QModelIndex>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWidget w;
    w.show();

//------------------------------------------窗口创建与布局
//    QWidget *window = new QWidget();
//    //新建label进行布局
//    QLabel *label = new QLabel(QObject::tr("Name:"));
//    QLineEdit *lineEdit = new QLineEdit();
//    QHBoxLayout *layout = new QHBoxLayout();
//    layout->addWidget(label);
//    layout->addWidget(lineEdit);
//    window->setLayout(layout);

//    window->resize(320, 240);
//    window->show();
//    QPushButton *button = new QPushButton(QObject::tr("Press me"), window);
//    button->move(20, 20);
//    button->show();
//--------------------------------------------------复杂窗口显示
//    QWidget *window = new QWidget();
//    QLabel *queryLabel = new QLabel();
//    QLineEdit *queryEdit = new QLineEdit();
//    QTableView *resultView = new QTableView();
//    QHBoxLayout *queryLayout = new QHBoxLayout();

//    queryLayout->addWidget(queryLabel);
//    queryLayout->addWidget(queryEdit);

//    QVBoxLayout *mainLayout = new QVBoxLayout();
//    mainLayout->addLayout(queryLayout);
//    mainLayout->addWidget(resultView);
//    window->setLayout(mainLayout);

//    window->show();
//-------------------------------------------------实现模型和视图的绑定
//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("employee");
//    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//    model->select();
//    model->removeColumn(0);
//    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
//    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Salary"));
//    QTableView *view = new QTableView();
//    view->setModel(model);
//    view->show();



    return a.exec();
}
