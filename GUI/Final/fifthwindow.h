#ifndef FIFTHWINDOW_H
#define FIFTHWINDOW_H

#include <QDialog>

namespace Ui {
class FifthWindow;
}

class FifthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FifthWindow(QWidget *parent = nullptr);
    ~FifthWindow();

private:
    Ui::FifthWindow *ui;
};

#endif // FIFTHWINDOW_H
