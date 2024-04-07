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

    m_model->setHorizontalHeaderLabels({"Dorm Name","Number of Channels","No of Songs Per Channel"});

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        QList<QStandardItem*> rowItems;
        for(const QString& field : fields)
        {
            QStandardItem *item = new QStandardItem(field);
            item->setTextAlignment(Qt::AlignJustify);
            rowItems.append(item);
        }
        m_model->appendRow(rowItems);
    }

    file.close();

    ui->tableView->resizeColumnsToContents();

    for (int i = 0; i < m_model->columnCount(); ++i) {
        ui->tableView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}

void ThirdWindow::on_pushButton_clicked()
{
    hide();
    fourth = new FourthWindow(this);
    fourth->show();
}

