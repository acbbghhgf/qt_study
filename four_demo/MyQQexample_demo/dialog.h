#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "drawer.h"
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    Drawer *drawer;
};
#endif // DIALOG_H
