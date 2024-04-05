#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include "thirdwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked()){
        SecondWindow a;
        a.setModal(true);
        a.exec();
    }
    if(ui->radioButton_2->isChecked()){
        ThirdWindow b;
        b.setModal(true);
        b.exec();
    }
    if(ui->radioButton->isChecked()==false && ui->radioButton_2->isChecked()==false){
        QMessageBox::critical(this, "Warning","Please Select one Option of the above");
    }
}

