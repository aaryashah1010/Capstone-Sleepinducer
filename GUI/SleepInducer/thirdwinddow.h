#ifndef THIRDWINDDOW_H
#define THIRDWINDDOW_H

#include <QDialog>
#include "fourthwindow.h"

namespace Ui {
class thirdwinddow;
}

class thirdwinddow : public QDialog
{
    Q_OBJECT

public:
    explicit thirdwinddow(QWidget *parent = nullptr);
    ~thirdwinddow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::thirdwinddow *ui;
    fourthwindow *fourth;
};

#endif // THIRDWINDDOW_H
