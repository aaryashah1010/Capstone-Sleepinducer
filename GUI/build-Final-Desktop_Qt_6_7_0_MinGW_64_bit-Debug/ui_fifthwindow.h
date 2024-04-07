/********************************************************************************
** Form generated from reading UI file 'fifthwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIFTHWINDOW_H
#define UI_FIFTHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_FifthWindow
{
public:
    QTableView *tableView;

    void setupUi(QDialog *FifthWindow)
    {
        if (FifthWindow->objectName().isEmpty())
            FifthWindow->setObjectName("FifthWindow");
        FifthWindow->resize(555, 367);
        tableView = new QTableView(FifthWindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 531, 341));

        retranslateUi(FifthWindow);

        QMetaObject::connectSlotsByName(FifthWindow);
    } // setupUi

    void retranslateUi(QDialog *FifthWindow)
    {
        FifthWindow->setWindowTitle(QCoreApplication::translate("FifthWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FifthWindow: public Ui_FifthWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIFTHWINDOW_H
