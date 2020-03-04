#include "dialog.h"
#include "digiclock.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    DigiClock clock(this);
    clock.show();
}

Dialog::~Dialog()
{
}

