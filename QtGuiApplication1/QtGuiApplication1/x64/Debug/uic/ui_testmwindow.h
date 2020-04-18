/********************************************************************************
** Form generated from reading UI file 'testmwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMWINDOW_H
#define UI_TESTMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestMWindow
{
public:
    QWidget *centralWidget;
    QTreeWidget *treeWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QRadioButton *radioButton;
    QToolButton *toolButton;
    QCheckBox *checkBox;
    QDialogButtonBox *buttonBox;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestMWindow)
    {
        if (TestMWindow->objectName().isEmpty())
            TestMWindow->setObjectName(QStringLiteral("TestMWindow"));
        TestMWindow->resize(736, 579);
        centralWidget = new QWidget(TestMWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(290, 50, 256, 192));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(240, 320, 120, 87));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 118, 85));
        scrollArea->setWidget(scrollAreaWidgetContents);
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(120, 60, 115, 19));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(80, 210, 47, 21));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(60, 180, 91, 19));
        buttonBox = new QDialogButtonBox(centralWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(480, 300, 193, 28));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(500, 400, 120, 80));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 320, 113, 21));
        TestMWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestMWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 736, 26));
        TestMWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestMWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TestMWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestMWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestMWindow->setStatusBar(statusBar);

        retranslateUi(TestMWindow);

        QMetaObject::connectSlotsByName(TestMWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TestMWindow)
    {
        TestMWindow->setWindowTitle(QApplication::translate("TestMWindow", "TestMWindow", Q_NULLPTR));
        radioButton->setText(QApplication::translate("TestMWindow", "RadioButton", Q_NULLPTR));
        toolButton->setText(QApplication::translate("TestMWindow", "...", Q_NULLPTR));
        checkBox->setText(QApplication::translate("TestMWindow", "CheckBox", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestMWindow: public Ui_TestMWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMWINDOW_H
