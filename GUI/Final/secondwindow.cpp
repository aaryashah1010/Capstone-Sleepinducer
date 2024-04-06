#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>

SecondWindow::SecondWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    m_model = new QStandardItemModel(this);
    ui->tableView->setModel(m_model);

    loadDataFromFile(":/Text/Text/inmates.txt");
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::loadDataFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
        return;
    }

    m_model->setHorizontalHeaderLabels({"Name", "Ear ID", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Duration"});

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        QList<QStandardItem*> rowItems;
        for(const QString& field : fields)
        {
            rowItems.append(new QStandardItem(field));
        }
        m_model->appendRow(rowItems);
    }

    file.close();
}


void SecondWindow::on_pushButton_clicked()
{
    hide();
    third = new ThirdWindow(this);
    third->show();
}

