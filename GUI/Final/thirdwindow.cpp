#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>

ThirdWindow::ThirdWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ThirdWindow)
{
    ui->setupUi(this);

    m_model = new QStandardItemModel(this);
    ui->tableView->setModel(m_model);

    loadDataFromFile(":/Text/Text/dorm.txt");
}

ThirdWindow::~ThirdWindow()
{
    delete ui;
}

void ThirdWindow::loadDataFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
        return;
    }

    m_model->setHorizontalHeaderLabels({"Dorm Name","Number of Students","Preference 1", "Preference 2", "Preference 3", "Preference 4"});

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

