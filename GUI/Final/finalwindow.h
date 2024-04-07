#ifndef FINALWINDOW_H
#define FINALWINDOW_H

#include <QDialog>

namespace Ui {
class FinalWindow;
}

class FinalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FinalWindow(QWidget *parent = nullptr);
    ~FinalWindow();

private:
    Ui::FinalWindow *ui;
};

#endif // FINALWINDOW_H
