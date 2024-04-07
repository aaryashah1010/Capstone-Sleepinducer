/********************************************************************************
** Form generated from reading UI file 'finalwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINALWINDOW_H
#define UI_FINALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_FinalWindow
{
public:
    QLabel *label;

    void setupUi(QDialog *FinalWindow)
    {
        if (FinalWindow->objectName().isEmpty())
            FinalWindow->setObjectName("FinalWindow");
        FinalWindow->resize(400, 300);
        label = new QLabel(FinalWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 130, 67, 20));

        retranslateUi(FinalWindow);

        QMetaObject::connectSlotsByName(FinalWindow);
    } // setupUi

    void retranslateUi(QDialog *FinalWindow)
    {
        FinalWindow->setWindowTitle(QCoreApplication::translate("FinalWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FinalWindow", "Thank You", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FinalWindow: public Ui_FinalWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINALWINDOW_H
