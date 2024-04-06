#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QStandardItemModel>
#include "thirdwindow.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SecondWindow *ui;
    QStandardItemModel *m_model;
    void loadDataFromFile(const QString& fileName);
    ThirdWindow *third;
};

#endif // SECONDWINDOW_H
