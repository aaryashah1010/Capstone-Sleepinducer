#ifndef FOURTHWINDOW_H
#define FOURTHWINDOW_H

#include <QDialog>
#include "fifthwindow.h"

namespace Ui {
class FourthWindow;
}

class FourthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FourthWindow(QWidget *parent = nullptr);
    ~FourthWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::FourthWindow *ui;
    FifthWindow *fifth;
};

#endif // FOURTHWINDOW_H
