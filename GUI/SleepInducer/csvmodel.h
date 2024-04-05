#ifndef CSVMODEL_H
#define CSVMODEL_H

#include <QObject>
#include <QStandardItemModel>

class CSVModel : public QObject
{
    Q_OBJECT
public:
    explicit CSVModel(QObject *parent = nullptr);

    void readCSVFile(const QString& filePath);

    QStandardItemModel* getModel();

private:
    QStandardItemModel m_model;
};

#endif
