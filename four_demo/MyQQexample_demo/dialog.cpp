#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    drawer = new Drawer(this);
    drawer->show();
}

Dialog::~Dialog()
{
}

