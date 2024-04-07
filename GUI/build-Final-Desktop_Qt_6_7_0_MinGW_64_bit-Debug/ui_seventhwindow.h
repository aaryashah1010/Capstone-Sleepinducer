/********************************************************************************
** Form generated from reading UI file 'seventhwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEVENTHWINDOW_H
#define UI_SEVENTHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_SeventhWindow
{
public:
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *SeventhWindow)
    {
        if (SeventhWindow->objectName().isEmpty())
            SeventhWindow->setObjectName("SeventhWindow");
        SeventhWindow->resize(696, 434);
        tableView = new QTableView(SeventhWindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 10, 681, 381));
        pushButton = new QPushButton(SeventhWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(610, 400, 83, 29));
        pushButton_2 = new QPushButton(SeventhWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(290, 400, 94, 29));

        retranslateUi(SeventhWindow);

        QMetaObject::connectSlotsByName(SeventhWindow);
    } // setupUi

    void retranslateUi(QDialog *SeventhWindow)
    {
        SeventhWindow->setWindowTitle(QCoreApplication::translate("SeventhWindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("SeventhWindow", "Next", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SeventhWindow", "Display Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SeventhWindow: public Ui_SeventhWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEVENTHWINDOW_H
