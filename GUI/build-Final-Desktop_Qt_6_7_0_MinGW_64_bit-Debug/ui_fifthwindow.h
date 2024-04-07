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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FifthWindow
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *FifthWindow)
    {
        if (FifthWindow->objectName().isEmpty())
            FifthWindow->setObjectName("FifthWindow");
        FifthWindow->resize(566, 584);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FifthWindow->sizePolicy().hasHeightForWidth());
        FifthWindow->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(FifthWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 540, 223, 29));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        retranslateUi(FifthWindow);

        QMetaObject::connectSlotsByName(FifthWindow);
    } // setupUi

    void retranslateUi(QDialog *FifthWindow)
    {
        FifthWindow->setWindowTitle(QCoreApplication::translate("FifthWindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("FifthWindow", "Clcik Here to Check Music Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FifthWindow: public Ui_FifthWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIFTHWINDOW_H
