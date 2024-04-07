#ifndef MUSIC_H
#define MUSIC_H

#include <QDialog>
#include "sixthwindow.h"

namespace Ui {
class music;
}

class music : public QDialog
{
    Q_OBJECT

public:
    explicit music(QWidget *parent = nullptr);
    ~music();

private slots:
    void on_pushButton_clicked();

private:
    Ui::music *ui;
    SixthWindow *sixth;
};

#endif // MUSIC_H
