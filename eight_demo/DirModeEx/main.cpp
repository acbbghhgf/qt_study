#include "mainwindow.h"
#include <QApplication>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QDirModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //新建一个QDirModel对象，为数据访问做准备，此外还可以设置过滤器。
    //QDirmodel为访问本地文件系统提供数据模型，提供了新建、删除、创建目录等一系列与文件操作相关的函数。
    QDirModel model;
    /* 新建三种不同的View对象，以便文件目录可以以三种不同的方式显示 */
    QTreeView tree;
    QListView list;
    QTableView table;
    //调用setModel函数设置View对象的model为QDirmodel。
    tree.setModel(&model);
    list.setModel(&model);
    table.setModel(&model);
    //设置QTreeView对象的选择方式为多选方式。
    tree.setSelectionMode(QAbstractItemView::MultiSelection);
    //设置QListView对象与QTreeView对象使用相同的选择模型。
    list.setSelectionModel(tree.selectionModel());
    //设置QTableView对象与QTreeView对象使用相同的选择模型。
    table.setSelectionModel(tree.selectionModel());
    QObject::connect(&tree,SIGNAL(doubleClicked(QModelIndex)),&list,
                           SLOT(setRootIndex(QModelIndex)));
    //实现双机对象中某一目录时显示此目录下的所以文件和目录，需要连接QTreeView对象的doubleClicked信号
    //与QListView对象和QTableView对象的setRootIndex槽函数。
    QObject::connect(&tree,SIGNAL(doubleClicked(QModelIndex)),&table,
                           SLOT(setRootIndex(QModelIndex)));
    QSplitter *splitter = new QSplitter;
    splitter->addWidget(&tree);
    splitter->addWidget(&list);
    splitter->addWidget(&table);
    splitter->setWindowTitle(QObject::tr("Model/View"));
    splitter->show();

    //MainWindow w;
    //w.show();

    return a.exec();
}
