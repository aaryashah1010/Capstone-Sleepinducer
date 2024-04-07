#include "sixthwindow.h"
#include "ui_sixthwindow.h"
#include <QMessageBox>

SixthWindow::SixthWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SixthWindow)
{
    ui->setupUi(this);
}

SixthWindow::~SixthWindow()
{
    delete ui;
}

void SixthWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()){
        hide();
        seventh = new SeventhWindow(this);
        seventh->show();
    }
    if(ui->radioButton_2->isChecked()){
        close();
    }
    if(ui->radioButton->isChecked()==false && ui->radioButton_2->isChecked()==false){
        QMessageBox::critical(this, "Warning","Please Select one Option of the above");
    }
}

