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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QProgressBar *progressBar;
    QPushButton *pushButton3;
    QComboBox *comboBox;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_10;
    QMenuBar *menuBar;
    QMenu *menuSwitchTo;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PMPTrans)
    {
        if (PMPTrans->objectName().isEmpty())
            PMPTrans->setObjectName(QStringLiteral("PMPTrans"));
        PMPTrans->resize(1800, 960);
        QFont font;
        font.setFamily(QString::fromUtf8(".\350\213\271\346\226\271-\347\256\200"));
        PMPTrans->setFont(font);
        PMPTrans->setStyleSheet(QStringLiteral("QMainWindow{background-color: white;}"));
        actionFTP = new QAction(PMPTrans);
        actionFTP->setObjectName(QStringLiteral("actionFTP"));
        actionFTP->setFont(font);
        actionOpen = new QAction(PMPTrans);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen->setFont(font);
        actionSave = new QAction(PMPTrans);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setFont(font);
        centralWidget = new QWidget(PMPTrans);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(250, 40, 1020, 820));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::tab-bar{ alignment: center;}\n"
"QTabBar::tab:selected{ background-color: rgb(0, 122, 255);color: white; }\n"
"\n"
"QTabBar::tab{ width: 130px; height:25px; border-radius: 4px; margin-bottom: 6px;}\342\200\213"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label1_1 = new QLabel(tab);
        label1_1->setObjectName(QStringLiteral("label1_1"));
        label1_1->setGeometry(QRect(0, 0, 500, 360));
        QFont font1;
        label1_1->setFont(font1);
        label1_4 = new QLabel(tab);
        label1_4->setObjectName(QStringLiteral("label1_4"));
        label1_4->setGeometry(QRect(520, 390, 500, 360));
        label1_4->setFont(font1);
        label1_3 = new QLabel(tab);
        label1_3->setObjectName(QStringLiteral("label1_3"));
        label1_3->setGeometry(QRect(0, 390, 500, 360));
        label1_3->setFont(font1);
        label1_2 = new QLabel(tab);
        label1_2->setObjectName(QStringLiteral("label1_2"));
        label1_2->setGeometry(QRect(520, 0, 500, 360));
        label1_2->setFont(font1);
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(730, 760, 71, 16));
        label_6->setFont(font);
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(740, 370, 61, 16));
        label_7->setFont(font);
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(230, 370, 51, 16));
        label_8->setFont(font);
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(230, 760, 51, 16));
        label_9->setFont(font);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label2_2 = new QLabel(tab_2);
        label2_2->setObjectName(QStringLiteral("label2_2"));
        label2_2->setGeometry(QRect(520, 0, 500, 360));
        label2_1 = new QLabel(tab_2);
        label2_1->setObjectName(QStringLiteral("label2_1"));
        label2_1->setGeometry(QRect(0, 0, 500, 360));
        label2_3 = new QLabel(tab_2);
        label2_3->setObjectName(QStringLiteral("label2_3"));
        label2_3->setGeometry(QRect(0, 390, 500, 360));
        label2_4 = new QLabel(tab_2);
        label2_4->setObjectName(QStringLiteral("label2_4"));
        label2_4->setGeometry(QRect(520, 390, 500, 360));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 370, 51, 16));
        label->setFont(font);
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(740, 370, 61, 16));
        label_2->setFont(font);
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 760, 51, 16));
        label_3->setFont(font);
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(730, 760, 71, 16));
        label_4->setFont(font);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label3_1 = new QLabel(tab_3);
        label3_1->setObjectName(QStringLiteral("label3_1"));
        label3_1->setGeometry(QRect(0, 80, 500, 500));
        label3_2 = new QLabel(tab_3);
        label3_2->setObjectName(QStringLiteral("label3_2"));
        label3_2->setGeometry(QRect(520, 80, 500, 500));
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(205, 620, 91, 16));
        label_14->setFont(font);
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(715, 620, 111, 16));
        label_15->setFont(font);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label4_2 = new QLabel(tab_4);
        label4_2->setObjectName(QStringLiteral("label4_2"));
        label4_2->setGeometry(QRect(520, 80, 500, 500));
        label_17 = new QLabel(tab_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(685, 620, 171, 16));
        label_17->setFont(font);
        label4_1 = new QLabel(tab_4);
        label4_1->setObjectName(QStringLiteral("label4_1"));
        label4_1->setGeometry(QRect(0, 80, 500, 500));
        label_18 = new QLabel(tab_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(180, 620, 151, 16));
        label_18->setFont(font);
        tabWidget->addTab(tab_4, QString());
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(670, 10, 201, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8(".\350\213\271\346\226\271-\347\256\200"));
        font2.setPointSize(10);
        label_5->setFont(font2);
        labelStatus = new QLabel(centralWidget);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));
        labelStatus->setGeometry(QRect(10, 860, 631, 16));
        labelStatus->setFont(font);
        pushButton1 = new QPushButton(centralWidget);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));
        pushButton1->setGeometry(QRect(10, 490, 111, 41));
        pushButton1->setFont(font);
        pushButton2 = new QPushButton(centralWidget);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));
        pushButton2->setGeometry(QRect(10, 570, 111, 41));
        pushButton2->setFont(font);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(1170, 860, 118, 23));
        progressBar->setFont(font);
        progressBar->setValue(24);
        pushButton3 = new QPushButton(centralWidget);
        pushButton3->setObjectName(QStringLiteral("pushButton3"));
        pushButton3->setGeometry(QRect(10, 650, 111, 41));
        pushButton3->setFont(font);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(80, 20, 165, 35));
        comboBox->setFont(font2);
        comboBox->setStyleSheet(QLatin1String("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 4px;\n"
"    padding: 1px 2px 1px 2px; \n"
"    min-width: 9em; \n"
"}\n"
"QComboBox::drop-down{width: 25px;border-left: 1px solid gray;}\n"
"\n"
"QComboBox::down-arrow { image: url(:/Reconstruction/Resources/arrowd.ico)}\n"
"\n"
"QComboBox::down-arrow:on {image: url(:/Reconstruction/Resources/arrowa.ico);}\n"
"\n"
"QComboBox QAbstractItemView {outline:0px;}\n"
"\n"
"QComboBox QAbstractItemView::item:hover {color: white;background-color: rgb(0, 122, 255);}\n"
"\n"
""));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(-3, 60, 1801, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(240, 80, 20, 801));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 10, 50, 50));
        label_10->setStyleSheet(QLatin1String("QLabel{border-image: url(:/Reconstruction/Resources/4.ico)}\n"
""));
        PMPTrans->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PMPTrans);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1800, 26));
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
        statusBar->setFont(font);
        statusBar->setAutoFillBackground(true);
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

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(PMPTrans);
    } // setupUi

    void retranslateUi(QMainWindow *PMPTrans)
    {
        PMPTrans->setWindowTitle(QApplication::translate("PMPTrans", "PMPTrans", Q_NULLPTR));
        actionFTP->setText(QApplication::translate("PMPTrans", "FTP", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("PMPTrans", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("PMPTrans", "Save", Q_NULLPTR));
        label1_1->setText(QString());
        label1_4->setText(QString());
        label1_3->setText(QString());
        label1_2->setText(QString());
        label_6->setText(QApplication::translate("PMPTrans", "3pi/2\347\233\270\344\275\215", Q_NULLPTR));
        label_7->setText(QApplication::translate("PMPTrans", "pi/2\347\233\270\344\275\215", Q_NULLPTR));
        label_8->setText(QApplication::translate("PMPTrans", "0\347\233\270\344\275\215", Q_NULLPTR));
        label_9->setText(QApplication::translate("PMPTrans", "pi\347\233\270\344\275\215", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("PMPTrans", "\350\260\203\345\210\266\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        label2_2->setText(QString());
        label2_1->setText(QString());
        label2_3->setText(QString());
        label2_4->setText(QString());
        label->setText(QApplication::translate("PMPTrans", "0\347\233\270\344\275\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("PMPTrans", "pi/2\347\233\270\344\275\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("PMPTrans", "pi\347\233\270\344\275\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("PMPTrans", "3pi/2\347\233\270\344\275\215", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("PMPTrans", "\345\216\237\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        label3_1->setText(QString());
        label3_2->setText(QString());
        label_14->setText(QApplication::translate("PMPTrans", "\345\216\237\345\205\211\346\240\205\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        label_15->setText(QApplication::translate("PMPTrans", "\350\260\203\345\210\266\345\205\211\346\240\205\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("PMPTrans", "\345\214\205\350\243\271\347\233\270\344\275\215\345\233\276\345\203\217", Q_NULLPTR));
        label4_2->setText(QString());
        label_17->setText(QApplication::translate("PMPTrans", "\350\247\243\345\214\205\350\243\271\345\220\216\347\211\251\344\275\223\345\256\236\351\231\205\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        label4_1->setText(QString());
        label_18->setText(QApplication::translate("PMPTrans", "\345\214\205\350\243\271\347\232\204\347\211\251\344\275\223\345\256\236\351\231\205\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("PMPTrans", "\350\247\243\345\214\205\350\243\271\345\220\216\347\233\270\344\275\215\345\233\276\345\203\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("PMPTrans", "\347\233\270\347\247\273\350\275\256\345\273\223\346\234\257\345\233\276\345\203\217\345\244\204\347\220\206\347\273\223\346\236\234", Q_NULLPTR));
        labelStatus->setText(QApplication::translate("PMPTrans", "TextLabel", Q_NULLPTR));
        pushButton1->setText(QApplication::translate("PMPTrans", "\346\261\202\347\233\270\344\275\215", Q_NULLPTR));
        pushButton2->setText(QApplication::translate("PMPTrans", "\347\233\270\344\275\215\350\247\243\345\214\205\350\243\271", Q_NULLPTR));
        pushButton3->setText(QApplication::translate("PMPTrans", "\344\270\211\347\273\264\351\207\215\345\273\272", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("PMPTrans", "\345\233\276\345\203\217\345\244\204\347\220\206", Q_NULLPTR)
         << QApplication::translate("PMPTrans", "\344\270\211\347\273\264\346\250\241\345\236\213\351\242\204\350\247\210", Q_NULLPTR)
        );
        label_10->setText(QString());
        menuSwitchTo->setTitle(QApplication::translate("PMPTrans", "SwitchTo", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("PMPTrans", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PMPTrans: public Ui_PMPTrans {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PMPTRANS_H
