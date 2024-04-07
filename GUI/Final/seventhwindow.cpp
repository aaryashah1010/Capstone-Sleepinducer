#include "seventhwindow.h"
#include "ui_seventhwindow.h"

SeventhWindow::SeventhWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SeventhWindow)
{
    ui->setupUi(this);
}

SeventhWindow::~SeventhWindow()
{
    delete ui;
}

void SeventhWindow::on_pushButton_clicked()
{
    hide();
    final = new FinalWindow(this);
    final->show();
}

