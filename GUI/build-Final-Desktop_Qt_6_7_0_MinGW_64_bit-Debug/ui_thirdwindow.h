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
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ThirdWindow
{
public:
    QLabel *label;
    QTableView *tableView;

    void setupUi(QDialog *ThirdWindow)
    {
        if (ThirdWindow->objectName().isEmpty())
            ThirdWindow->setObjectName("ThirdWindow");
        ThirdWindow->resize(904, 491);
        label = new QLabel(ThirdWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 60, 94, 20));
        tableView = new QTableView(ThirdWindow);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(5, 91, 891, 391));

        retranslateUi(ThirdWindow);

        QMetaObject::connectSlotsByName(ThirdWindow);
    } // setupUi

    void retranslateUi(QDialog *ThirdWindow)
    {
        ThirdWindow->setWindowTitle(QCoreApplication::translate("ThirdWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ThirdWindow", "Dorms Details", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThirdWindow: public Ui_ThirdWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRDWINDOW_H
