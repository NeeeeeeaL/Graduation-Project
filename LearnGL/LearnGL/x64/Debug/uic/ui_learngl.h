/********************************************************************************
** Form generated from reading UI file 'learngl.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNGL_H
#define UI_LEARNGL_H

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

class Ui_LearnGLClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LearnGLClass)
    {
        if (LearnGLClass->objectName().isEmpty())
            LearnGLClass->setObjectName(QStringLiteral("LearnGLClass"));
        LearnGLClass->resize(600, 400);
        menuBar = new QMenuBar(LearnGLClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        LearnGLClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LearnGLClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LearnGLClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(LearnGLClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LearnGLClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LearnGLClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LearnGLClass->setStatusBar(statusBar);

        retranslateUi(LearnGLClass);

        QMetaObject::connectSlotsByName(LearnGLClass);
    } // setupUi

    void retranslateUi(QMainWindow *LearnGLClass)
    {
        LearnGLClass->setWindowTitle(QApplication::translate("LearnGLClass", "LearnGL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LearnGLClass: public Ui_LearnGLClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNGL_H
