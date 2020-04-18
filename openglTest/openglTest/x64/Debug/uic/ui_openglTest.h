/********************************************************************************
** Form generated from reading UI file 'openglTest.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENGLTEST_H
#define UI_OPENGLTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_openglTestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *openglTestClass)
    {
        if (openglTestClass->objectName().isEmpty())
            openglTestClass->setObjectName(QStringLiteral("openglTestClass"));
        openglTestClass->resize(600, 400);
        menuBar = new QMenuBar(openglTestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        openglTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(openglTestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        openglTestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(openglTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openglTestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(openglTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        openglTestClass->setStatusBar(statusBar);

        retranslateUi(openglTestClass);

        QMetaObject::connectSlotsByName(openglTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *openglTestClass)
    {
        openglTestClass->setWindowTitle(QApplication::translate("openglTestClass", "openglTest", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class openglTestClass: public Ui_openglTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENGLTEST_H
