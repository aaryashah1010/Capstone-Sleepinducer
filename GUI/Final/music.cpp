#include "music.h"
#include "ui_music.h"

music::music(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::music)
{
    ui->setupUi(this);
}

music::~music()
{
    delete ui;
}

void music::on_pushButton_clicked()
{
    hide();
    sixth = new SixthWindow(this);
    sixth->show();
}

