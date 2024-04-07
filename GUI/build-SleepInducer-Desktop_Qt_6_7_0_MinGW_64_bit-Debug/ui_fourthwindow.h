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

class Ui_fourthwindow
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *fourthwindow)
    {
        if (fourthwindow->objectName().isEmpty())
            fourthwindow->setObjectName("fourthwindow");
        fourthwindow->resize(400, 300);
        pushButton = new QPushButton(fourthwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 270, 83, 29));
        pushButton_2 = new QPushButton(fourthwindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(0, 270, 83, 29));

        retranslateUi(fourthwindow);
        QObject::connect(pushButton, &QPushButton::clicked, fourthwindow, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(fourthwindow);
    } // setupUi

    void retranslateUi(QDialog *fourthwindow)
    {
        fourthwindow->setWindowTitle(QCoreApplication::translate("fourthwindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("fourthwindow", "Exit", nullptr));
        pushButton_2->setText(QCoreApplication::translate("fourthwindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fourthwindow: public Ui_fourthwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOURTHWINDOW_H
