#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QDialog>
#include <QStandardItemModel>
#include "fourthwindow.h"

namespace Ui {
class ThirdWindow;
}

class ThirdWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdWindow(QWidget *parent = nullptr);
    ~ThirdWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ThirdWindow *ui;
    QStandardItemModel *m_model;
    void loadDataFromFile(const QString& fileName);
    FourthWindow *fourth;
};

#endif // THIRDWINDOW_H
