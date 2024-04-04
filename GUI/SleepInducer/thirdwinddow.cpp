#include "thirdwinddow.h"
#include "ui_thirdwinddow.h"

thirdwinddow::thirdwinddow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::thirdwinddow)
{
    ui->setupUi(this);
}

thirdwinddow::~thirdwinddow()
{
    delete ui;
}

void thirdwinddow::on_pushButton_clicked()
{
    hide();
    fourth = new fourthwindow(this);
    fourth->show();
}

