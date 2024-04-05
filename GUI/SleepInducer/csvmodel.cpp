// CSVModel.cpp
#include "csvmodel.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <QStringList>

CSVModel::CSVModel(QObject *parent) : QObject(parent)
{
    // Set column headers
    m_model.setHorizontalHeaderLabels({"Name", "Ear id", "Minutes", "Daily sleep time"});
}

void CSVModel::readCSVFile(const QString& filePath)
{
    // Open the CSV file
    std::ifstream file(filePath.toStdString());
    if (!file.is_open()) {
        // Handle error
        return;
    }

    // Read the file line by line
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> row;

        // Read each field separated by comma
        std::string field;
        while (std::getline(ss, field, ',')) {
            // Add the field to the row
            row.push_back(field);
        }

        // Create a new row in the model
        QList<QStandardItem*> items;
        for (const auto& field : row) {
            items.append(new QStandardItem(QString::fromStdString(field)));
        }
        m_model.appendRow(items);
    }

    // Close the file
    file.close();
}

QStandardItemModel* CSVModel::getModel()
{
    return &m_model;
}
