/********************************************************************************
** Form generated from reading UI file 'thirdwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRDWINDOW_H
#define UI_THIRDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ThirdWindow
{
public:
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QDialog *ThirdWindow)
    {
        if (ThirdWindow->objectName().isEmpty())
            ThirdWindow->setObjectName("ThirdWindow");
        ThirdWindow->resize(662, 563);
        tableView = new QTableView(ThirdWindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 20, 621, 491));
        pushButton = new QPushButton(ThirdWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(560, 520, 83, 29));

        retranslateUi(ThirdWindow);

        QMetaObject::connectSlotsByName(ThirdWindow);
    } // setupUi

    void retranslateUi(QDialog *ThirdWindow)
    {
        ThirdWindow->setWindowTitle(QCoreApplication::translate("ThirdWindow", "Dorms Details", nullptr));
        pushButton->setText(QCoreApplication::translate("ThirdWindow", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThirdWindow: public Ui_ThirdWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRDWINDOW_H
