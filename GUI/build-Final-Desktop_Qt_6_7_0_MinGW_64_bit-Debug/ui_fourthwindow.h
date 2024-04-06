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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_FourthWindow
{
public:
    QPushButton *pushButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label;

    void setupUi(QDialog *FourthWindow)
    {
        if (FourthWindow->objectName().isEmpty())
            FourthWindow->setObjectName("FourthWindow");
        FourthWindow->resize(647, 392);
        pushButton_2 = new QPushButton(FourthWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(560, 360, 83, 29));
        radioButton = new QRadioButton(FourthWindow);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(220, 150, 112, 26));
        radioButton_2 = new QRadioButton(FourthWindow);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(220, 180, 112, 26));
        label = new QLabel(FourthWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 100, 240, 20));

        retranslateUi(FourthWindow);

        QMetaObject::connectSlotsByName(FourthWindow);
    } // setupUi

    void retranslateUi(QDialog *FourthWindow)
    {
        FourthWindow->setWindowTitle(QCoreApplication::translate("FourthWindow", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FourthWindow", "Next", nullptr));
        radioButton->setText(QCoreApplication::translate("FourthWindow", "Yes", nullptr));
        radioButton_2->setText(QCoreApplication::translate("FourthWindow", "No", nullptr));
        label->setText(QCoreApplication::translate("FourthWindow", "Do you want to assign Dormmates ?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FourthWindow: public Ui_FourthWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOURTHWINDOW_H
