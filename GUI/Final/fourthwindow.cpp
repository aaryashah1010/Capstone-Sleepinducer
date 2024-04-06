#include "fourthwindow.h"
#include "ui_fourthwindow.h"
#include <QMessageBox>

FourthWindow::FourthWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FourthWindow)
{
    ui->setupUi(this);
}

FourthWindow::~FourthWindow()
{
    delete ui;
}

void FourthWindow::on_pushButton_2_clicked()
{
    if(ui->radioButton->isChecked()){
        hide();
        fifth = new FifthWindow(this);
        fifth->show();
    }
    if(ui->radioButton_2->isChecked()){
        close();
    }
    if(ui->radioButton->isChecked()==false && ui->radioButton_2->isChecked()==false){
        QMessageBox::critical(this, "Warning","Please Select one Option of the above");
    }
}

