#include "mainwindow.h"
#include "fifthwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/icon/img/icon/sleeping.ico"));
    w.show();
    return a.exec();
}
