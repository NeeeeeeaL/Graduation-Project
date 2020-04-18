/********************************************************************************
** Form generated from reading UI file 'play.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAY_H
#define UI_PLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayClass
{
public:

    void setupUi(QWidget *PlayClass)
    {
        if (PlayClass->objectName().isEmpty())
            PlayClass->setObjectName(QStringLiteral("PlayClass"));
        PlayClass->resize(600, 400);

        retranslateUi(PlayClass);

        QMetaObject::connectSlotsByName(PlayClass);
    } // setupUi

    void retranslateUi(QWidget *PlayClass)
    {
        PlayClass->setWindowTitle(QApplication::translate("PlayClass", "Play", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PlayClass: public Ui_PlayClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAY_H
