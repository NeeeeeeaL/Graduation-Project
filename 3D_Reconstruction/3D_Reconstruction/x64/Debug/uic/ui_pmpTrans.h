/********************************************************************************
** Form generated from reading UI file 'pmpTrans.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PMPTRANS_H
#define UI_PMPTRANS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PMPTrans
{
public:
    QAction *actionFTP;
    QAction *actionOpen;
    QAction *actionSave;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label1_1;
    QLabel *label1_4;
    QLabel *label1_3;
    QLabel *label1_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *tab_2;
    QLabel *label2_2;
    QLabel *label2_1;
    QLabel *label2_3;
    QLabel *label2_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *tab_3;
    QLabel *label3_1;
    QLabel *label3_2;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *tab_4;
    QLabel *label4_2;
    QLabel *label_17;
    QLabel *label4_1;
    QLabel *label_18;
    QLabel *label_5;
    QLabel *labelStatus;
    QLabel *label_11;
    QListView *listView;
    QLabel *label_12;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QProgressBar *progressBar;
    QPushButton *pushButton3;
    QMenuBar *menuBar;
    QMenu *menuSwitchTo;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PMPTrans)
    {
        if (PMPTrans->objectName().isEmpty())
            PMPTrans->setObjectName(QStringLiteral("PMPTrans"));
        PMPTrans->resize(1440, 960);
        QFont font;
        font.setFamily(QString::fromUtf8(".\350\213\271\346\226\271-\347\256\200"));
        PMPTrans->setFont(font);
        actionFTP = new QAction(PMPTrans);
        actionFTP->setObjectName(QStringLiteral("actionFTP"));
        actionOpen = new QAction(PMPTrans);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(PMPTrans);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(PMPTrans);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 50, 851, 731));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label1_1 = new QLabel(tab);
        label1_1->setObjectName(QStringLiteral("label1_1"));
        label1_1->setGeometry(QRect(10, 10, 400, 300));
        label1_4 = new QLabel(tab);
        label1_4->setObjectName(QStringLiteral("label1_4"));
        label1_4->setGeometry(QRect(420, 350, 400, 300));
        label1_3 = new QLabel(tab);
        label1_3->setObjectName(QStringLiteral("label1_3"));
        label1_3->setGeometry(QRect(10, 350, 400, 300));
        label1_2 = new QLabel(tab);
        label1_2->setObjectName(QStringLiteral("label1_2"));
        label1_2->setGeometry(QRect(420, 10, 400, 300));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(590, 660, 71, 16));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(590, 320, 61, 16));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(190, 320, 51, 16));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(190, 660, 51, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label2_2 = new QLabel(tab_2);
        label2_2->setObjectName(QStringLiteral("label2_2"));
        label2_2->setGeometry(QRect(420, 10, 400, 300));
        label2_1 = new QLabel(tab_2);
        label2_1->setObjectName(QStringLiteral("label2_1"));
        label2_1->setGeometry(QRect(10, 10, 400, 300));
        label2_3 = new QLabel(tab_2);
        label2_3->setObjectName(QStringLiteral("label2_3"));
        label2_3->setGeometry(QRect(10, 350, 400, 300));
        label2_4 = new QLabel(tab_2);
        label2_4->setObjectName(QStringLiteral("label2_4"));
        label2_4->setGeometry(QRect(420, 350, 400, 300));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 320, 51, 16));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(590, 320, 61, 16));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 660, 51, 16));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(590, 660, 71, 16));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label3_1 = new QLabel(tab_3);
        label3_1->setObjectName(QStringLiteral("label3_1"));
        label3_1->setGeometry(QRect(10, 50, 400, 400));
        label3_2 = new QLabel(tab_3);
        label3_2->setObjectName(QStringLiteral("label3_2"));
        label3_2->setGeometry(QRect(430, 50, 400, 400));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(160, 460, 91, 16));
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(580, 460, 111, 16));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label4_2 = new QLabel(tab_4);
        label4_2->setObjectName(QStringLiteral("label4_2"));
        label4_2->setGeometry(QRect(430, 50, 400, 400));
        label_17 = new QLabel(tab_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(560, 460, 171, 16));
        label4_1 = new QLabel(tab_4);
        label4_1->setObjectName(QStringLiteral("label4_1"));
        label4_1->setGeometry(QRect(10, 50, 400, 400));
        label_18 = new QLabel(tab_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(130, 460, 171, 16));
        tabWidget->addTab(tab_4, QString());
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(290, 20, 72, 15));
        QFont font1;
        font1.setPointSize(10);
        label_5->setFont(font1);
        labelStatus = new QLabel(centralWidget);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));
        labelStatus->setGeometry(QRect(10, 860, 631, 16));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(1080, 10, 111, 16));
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignCenter);
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(890, 500, 511, 341));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(1100, 480, 71, 16));
        label_12->setFont(font1);
        pushButton1 = new QPushButton(centralWidget);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));
        pushButton1->setGeometry(QRect(110, 800, 111, 41));
        pushButton2 = new QPushButton(centralWidget);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));
        pushButton2->setGeometry(QRect(360, 800, 111, 41));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(1160, 850, 118, 23));
        progressBar->setValue(24);
        pushButton3 = new QPushButton(centralWidget);
        pushButton3->setObjectName(QStringLiteral("pushButton3"));
        pushButton3->setGeometry(QRect(600, 800, 111, 41));
        PMPTrans->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PMPTrans);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1440, 26));
        menuSwitchTo = new QMenu(menuBar);
        menuSwitchTo->setObjectName(QStringLiteral("menuSwitchTo"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        PMPTrans->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PMPTrans);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PMPTrans->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PMPTrans);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PMPTrans->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSwitchTo->menuAction());
        menuSwitchTo->addAction(actionFTP);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionFTP);
        mainToolBar->addSeparator();

        retranslateUi(PMPTrans);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PMPTrans);
    } // setupUi

    void retranslateUi(QMainWindow *PMPTrans)
    {
        PMPTrans->setWindowTitle(QApplication::translate("PMPTrans", "PMPTrans", Q_NULLPTR));
        actionFTP->setText(QApplication::translate("PMPTrans", "FTP", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("PMPTrans", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("PMPTrans", "Save", Q_NULLPTR));
        label1_1->setText(QApplication::translate("PMPTrans", "TextLabel", Q_NULLPTR));
        label1_4->setText(QApplication::translate("PMPTrans", "TextLabel", Q_NULLPTR));
        label1_3->setText(QApplication::translate("PMPTrans", "TextLabel", Q_NULLPTR));
        label1_2->setText(QApplication::translate("PMPTrans", "TextLabel", Q_NULLPTR));
        label_6->setText(QApplication::translate("PMPTrans", "3pi/2\347\233\270\344\275\215", Q_NULLPTR));
        label_7->setText(QApplication::translate("PMPTrans", "pi/2\347\233\270\344\275\215", Q_NULLPTR));
        label_8->setText(QApplication::translate("PMPTrans", "0\347\233\270\344\275\215", Q_NULLPTR));
        label_9->setText(QApplication::translate("PMPTrans", "pi\347\233\270\344\275\215", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("PMPTrans", "\350\260\203\345\210\266\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        label2_2->setText(QApplication::translate("PMPTrans", "TextLabel", Q_NULLPTR));
        label2_1->setText(QApplication::translate("PMPTrans", "TextLabel", Q_NULLPTR));
        label2_3->setText(QApplication::translate("PMPTrans", "TextLabel", Q_NULLPTR));
        label2_4->setText(QApplication::translate("PMPTrans", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("PMPTrans", "0\347\233\270\344\275\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("PMPTrans", "pi/2\347\233\270\344\275\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("PMPTrans", "pi\347\233\270\344\275\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("PMPTrans", "3pi/2\347\233\270\344\275\215", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("PMPTrans", "\345\216\237\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        label3_1->setText(QApplication::translate("PMPTrans", "TextLabel", Q_NULLPTR));
        label3_2->setText(QApplication::translate("PMPTrans", "TextLabel", Q_NULLPTR));
        label_14->setText(QApplication::translate("PMPTrans", "\345\216\237\345\205\211\346\240\205\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        label_15->setText(QApplication::translate("PMPTrans", "\350\260\203\345\210\266\345\205\211\346\240\205\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("PMPTrans", "\345\214\205\350\243\271\347\233\270\344\275\215\345\233\276\345\203\217", Q_NULLPTR));
        label4_2->setText(QApplication::translate("PMPTrans", "TextLabel", Q_NULLPTR));
        label_17->setText(QApplication::translate("PMPTrans", "\350\247\243\345\214\205\350\243\271\345\220\216\347\211\251\344\275\223\345\256\236\351\231\205\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        label4_1->setText(QApplication::translate("PMPTrans", "TextLabel", Q_NULLPTR));
        label_18->setText(QApplication::translate("PMPTrans", "\345\214\205\350\243\271\347\232\204\347\211\251\344\275\223\345\256\236\351\231\205\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("PMPTrans", "\350\247\243\345\214\205\350\243\271\345\220\216\347\233\270\344\275\215\345\233\276\345\203\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("PMPTrans", "\345\233\276\345\203\217\345\244\204\347\220\206", Q_NULLPTR));
        labelStatus->setText(QApplication::translate("PMPTrans", "TextLabel", Q_NULLPTR));
        label_11->setText(QApplication::translate("PMPTrans", "\346\225\260\346\215\256\347\273\237\350\256\241", Q_NULLPTR));
        label_12->setText(QApplication::translate("PMPTrans", "\346\225\260\346\215\256\345\210\206\346\236\220", Q_NULLPTR));
        pushButton1->setText(QApplication::translate("PMPTrans", "\346\261\202\347\233\270\344\275\215", Q_NULLPTR));
        pushButton2->setText(QApplication::translate("PMPTrans", "\347\233\270\344\275\215\350\247\243\345\214\205\350\243\271", Q_NULLPTR));
        pushButton3->setText(QApplication::translate("PMPTrans", "\344\270\211\347\273\264\351\207\215\345\273\272", Q_NULLPTR));
        menuSwitchTo->setTitle(QApplication::translate("PMPTrans", "SwitchTo", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("PMPTrans", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PMPTrans: public Ui_PMPTrans {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PMPTRANS_H
