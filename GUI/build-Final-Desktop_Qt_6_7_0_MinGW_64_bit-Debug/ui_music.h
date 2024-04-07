/********************************************************************************
** Form generated from reading UI file 'music.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSIC_H
#define UI_MUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_music
{
public:
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *music)
    {
        if (music->objectName().isEmpty())
            music->setObjectName("music");
        music->resize(788, 557);
        listWidget = new QListWidget(music);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(20, 10, 751, 491));
        pushButton = new QPushButton(music);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(580, 520, 197, 29));

        retranslateUi(music);

        QMetaObject::connectSlotsByName(music);
    } // setupUi

    void retranslateUi(QDialog *music)
    {
        music->setWindowTitle(QCoreApplication::translate("music", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("music", "Click Here to Update Details", nullptr));
    } // retranslateUi

};

namespace Ui {
    class music: public Ui_music {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSIC_H
