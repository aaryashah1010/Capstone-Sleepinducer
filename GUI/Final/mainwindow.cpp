#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include "thirdwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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
}

