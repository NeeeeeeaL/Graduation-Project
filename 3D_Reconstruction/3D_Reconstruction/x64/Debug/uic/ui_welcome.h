/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QGridLayout *gridLayout;
    QRadioButton *radioButton;
    QCheckBox *checkBox;
    QRadioButton *radioButton_2;
    QLabel *labelSplash;

    void setupUi(QWidget *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName(QStringLiteral("Welcome"));
        Welcome->resize(730, 498);
        QFont font;
        font.setFamily(QString::fromUtf8(".\350\213\271\346\226\271-\347\256\200"));
        Welcome->setFont(font);
        gridLayout = new QGridLayout(Welcome);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        radioButton = new QRadioButton(Welcome);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout->addWidget(radioButton, 1, 1, 1, 1);

        checkBox = new QCheckBox(Welcome);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 0, 1, 1, 1);

        radioButton_2 = new QRadioButton(Welcome);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout->addWidget(radioButton_2, 2, 1, 1, 1);

        labelSplash = new QLabel(Welcome);
        labelSplash->setObjectName(QStringLiteral("labelSplash"));

        gridLayout->addWidget(labelSplash, 0, 0, 3, 1);


        retranslateUi(Welcome);

        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QWidget *Welcome)
    {
        Welcome->setWindowTitle(QApplication::translate("Welcome", "Welcome", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Welcome", "RadioButton", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Welcome", "CheckBox", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("Welcome", "RadioButton", Q_NULLPTR));
        labelSplash->setText(QApplication::translate("Welcome", "\351\232\276\345\217\227\345\225\212", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
