#include "fifthwindow.h"
#include "ui_fifthwindow.h"

FifthWindow::FifthWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FifthWindow)
{
    ui->setupUi(this);
}

FifthWindow::~FifthWindow()
{
    delete ui;
}
