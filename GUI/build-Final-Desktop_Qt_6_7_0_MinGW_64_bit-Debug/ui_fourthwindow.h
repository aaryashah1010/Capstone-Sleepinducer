/********************************************************************************
** Form generated from reading UI file 'fourthwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOURTHWINDOW_H
#define UI_FOURTHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FourthWindow
{
public:
    QPushButton *pushButton_2;

    void setupUi(QDialog *FourthWindow)
    {
        if (FourthWindow->objectName().isEmpty())
            FourthWindow->setObjectName("FourthWindow");
        FourthWindow->resize(647, 392);
        pushButton_2 = new QPushButton(FourthWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(560, 360, 83, 29));

        retranslateUi(FourthWindow);
        QObject::connect(pushButton_2, &QPushButton::clicked, FourthWindow, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(FourthWindow);
    } // setupUi

    void retranslateUi(QDialog *FourthWindow)
    {
        FourthWindow->setWindowTitle(QCoreApplication::translate("FourthWindow", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FourthWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FourthWindow: public Ui_FourthWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOURTHWINDOW_H
