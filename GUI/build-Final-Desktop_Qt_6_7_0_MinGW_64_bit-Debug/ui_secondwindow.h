/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QDialog *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName("SecondWindow");
        SecondWindow->resize(1042, 524);
        tableView = new QTableView(SecondWindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 1021, 471));
        pushButton = new QPushButton(SecondWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(950, 490, 83, 29));

        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QDialog *SecondWindow)
    {
        SecondWindow->setWindowTitle(QCoreApplication::translate("SecondWindow", "Student Details", nullptr));
        pushButton->setText(QCoreApplication::translate("SecondWindow", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
