/********************************************************************************
** Form generated from reading UI file 'childWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHILDWINDOW_H
#define UI_CHILDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_childWindow
{
public:
    QPushButton *pushButtonSwitch;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_5;

    void setupUi(QWidget *childWindow)
    {
        if (childWindow->objectName().isEmpty())
            childWindow->setObjectName(QStringLiteral("childWindow"));
        childWindow->resize(1440, 960);
        QFont font;
        font.setFamily(QString::fromUtf8(".\350\213\271\346\226\271-\347\256\200"));
        childWindow->setFont(font);
        pushButtonSwitch = new QPushButton(childWindow);
        pushButtonSwitch->setObjectName(QStringLiteral("pushButtonSwitch"));
        pushButtonSwitch->setGeometry(QRect(0, 0, 151, 28));
        QFont font1;
        font1.setFamily(QString::fromUtf8(".\350\213\271\346\226\271-\347\256\200"));
        font1.setPointSize(10);
        pushButtonSwitch->setFont(font1);
        tabWidget = new QTabWidget(childWindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 80, 671, 571));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 0, 1, 1, 1);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 1, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());

        retranslateUi(childWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(childWindow);
    } // setupUi

    void retranslateUi(QWidget *childWindow)
    {
        childWindow->setWindowTitle(QApplication::translate("childWindow", "childWindow", Q_NULLPTR));
        pushButtonSwitch->setText(QApplication::translate("childWindow", "Switch To FTP", Q_NULLPTR));
        label->setText(QApplication::translate("childWindow", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("childWindow", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("childWindow", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("childWindow", "TextLabel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("childWindow", "\345\216\237\345\205\211\346\240\205\345\233\276", Q_NULLPTR));
        label_6->setText(QApplication::translate("childWindow", "TextLabel", Q_NULLPTR));
        label_8->setText(QApplication::translate("childWindow", "TextLabel", Q_NULLPTR));
        label_7->setText(QApplication::translate("childWindow", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("childWindow", "TextLabel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("childWindow", "\350\260\203\345\210\266\345\205\211\346\240\205\345\233\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class childWindow: public Ui_childWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHILDWINDOW_H
