/********************************************************************************
** Form generated from reading UI file 'sixthwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIXTHWINDOW_H
#define UI_SIXTHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_SixthWindow
{
public:
    QLabel *label;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *SixthWindow)
    {
        if (SixthWindow->objectName().isEmpty())
            SixthWindow->setObjectName("SixthWindow");
        SixthWindow->resize(705, 473);
        label = new QLabel(SixthWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 110, 232, 20));
        radioButton = new QRadioButton(SixthWindow);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(280, 180, 112, 26));
        radioButton_2 = new QRadioButton(SixthWindow);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(280, 230, 112, 26));
        pushButton = new QPushButton(SixthWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(610, 440, 83, 29));

        retranslateUi(SixthWindow);
        QObject::connect(pushButton, &QPushButton::clicked, SixthWindow, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(SixthWindow);
    } // setupUi

    void retranslateUi(QDialog *SixthWindow)
    {
        SixthWindow->setWindowTitle(QCoreApplication::translate("SixthWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SixthWindow", "Do you Want to Update the Details", nullptr));
        radioButton->setText(QCoreApplication::translate("SixthWindow", "Yes", nullptr));
        radioButton_2->setText(QCoreApplication::translate("SixthWindow", "No", nullptr));
        pushButton->setText(QCoreApplication::translate("SixthWindow", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SixthWindow: public Ui_SixthWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIXTHWINDOW_H
