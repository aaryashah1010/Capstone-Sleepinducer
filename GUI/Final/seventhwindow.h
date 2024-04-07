#ifndef SEVENTHWINDOW_H
#define SEVENTHWINDOW_H

#include <QDialog>
#include "finalwindow.h"

namespace Ui {
class SeventhWindow;
}

class SeventhWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SeventhWindow(QWidget *parent = nullptr);
    ~SeventhWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SeventhWindow *ui;
    FinalWindow *final;
};

#endif // SEVENTHWINDOW_H
