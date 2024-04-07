#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QListView>
#include "csvmodel.h"

secondwindow::secondwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::secondwindow)
{
    ui->setupUi(this);

    CSVModel csvModel;

    csvModel.readCSVFile(":/csv/csv/inmates1.csv");

    QStandardItemModel* model = csvModel.getModel();

    ui->listView->setModel(model);
}

secondwindow::~secondwindow()
{
    delete ui;
}

void secondwindow::on_pushButton_clicked()
{
    hide();
    third = new thirdwinddow(this);
    third->show();
}

