/********************************************************************************
** Form generated from reading UI file 'thirdwinddow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRDWINDDOW_H
#define UI_THIRDWINDDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_thirdwinddow
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *thirdwinddow)
    {
        if (thirdwinddow->objectName().isEmpty())
            thirdwinddow->setObjectName("thirdwinddow");
        thirdwinddow->resize(400, 300);
        pushButton = new QPushButton(thirdwinddow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(320, 270, 83, 29));

        retranslateUi(thirdwinddow);

        QMetaObject::connectSlotsByName(thirdwinddow);
    } // setupUi

    void retranslateUi(QDialog *thirdwinddow)
    {
        thirdwinddow->setWindowTitle(QCoreApplication::translate("thirdwinddow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("thirdwinddow", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thirdwinddow: public Ui_thirdwinddow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRDWINDDOW_H
