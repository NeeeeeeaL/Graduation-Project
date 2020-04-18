/********************************************************************************
** Form generated from reading UI file 'gltest.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLTEST_H
#define UI_GLTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GLTestClass
{
public:

    void setupUi(QWidget *GLTestClass)
    {
        if (GLTestClass->objectName().isEmpty())
            GLTestClass->setObjectName(QStringLiteral("GLTestClass"));
        GLTestClass->resize(600, 400);

        retranslateUi(GLTestClass);

        QMetaObject::connectSlotsByName(GLTestClass);
    } // setupUi

    void retranslateUi(QWidget *GLTestClass)
    {
        GLTestClass->setWindowTitle(QApplication::translate("GLTestClass", "GLTest", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GLTestClass: public Ui_GLTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLTEST_H
