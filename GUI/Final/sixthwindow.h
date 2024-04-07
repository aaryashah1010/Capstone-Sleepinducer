#ifndef SIXTHWINDOW_H
#define SIXTHWINDOW_H

#include <QDialog>
#include "seventhwindow.h"

namespace Ui {
class SixthWindow;
}

class SixthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SixthWindow(QWidget *parent = nullptr);
    ~SixthWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SixthWindow *ui;
    SeventhWindow *seventh;
};

#endif // SIXTHWINDOW_H
