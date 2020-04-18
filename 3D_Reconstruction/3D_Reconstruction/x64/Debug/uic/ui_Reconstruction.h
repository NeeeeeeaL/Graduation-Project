/********************************************************************************
** Form generated from reading UI file 'Reconstruction.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECONSTRUCTION_H
#define UI_RECONSTRUCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReconstructionClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionPMP;
    QWidget *centralWidget;
    QLabel *labelStatus;
    QFrame *frame;
    QToolBox *toolBox;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_7;
    QLabel *label;
    QLabel *label_2;
    QTabWidget *tabWidget1;
    QWidget *tab_7;
    QLabel *labelImg1_1;
    QWidget *tab_8;
    QLabel *labelImg1_2;
    QWidget *tab_9;
    QLabel *labelImg1_3;
    QWidget *tab_10;
    QLabel *labelImg1_4;
    QWidget *tab_11;
    QLabel *labelImg1_5;
    QWidget *tab_12;
    QLabel *labelImg1_6;
    QLabel *label_3;
    QTabWidget *tabWidget2;
    QWidget *tab_14;
    QLabel *labelImg2_1;
    QWidget *tab_15;
    QLabel *labelImg2_2;
    QWidget *tab_16;
    QLabel *labelImg2_3;
    QWidget *tab_17;
    QLabel *labelImg2_4;
    QWidget *tab_18;
    QLabel *labelImg2_5;
    QWidget *tab_19;
    QLabel *labelImg2_6;
    QLabel *label_4;
    QLabel *label_5;
    QTableView *tableView;
    QTextEdit *textEdit;
    QLabel *label_6;
    QTextEdit *textEdit_2;
    QLabel *label_7;
    QTextEdit *textEdit_3;
    QLabel *label_8;
    QProgressBar *progressBar;
    QFrame *line;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuswitchTo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ReconstructionClass)
    {
        if (ReconstructionClass->objectName().isEmpty())
            ReconstructionClass->setObjectName(QStringLiteral("ReconstructionClass"));
        ReconstructionClass->resize(1440, 960);
        ReconstructionClass->setMaximumSize(QSize(1440, 960));
        QFont font;
        font.setFamily(QString::fromUtf8(".\350\213\271\346\226\271-\347\256\200"));
        ReconstructionClass->setFont(font);
        ReconstructionClass->setMouseTracking(true);
        ReconstructionClass->setAnimated(true);
        actionOpen = new QAction(ReconstructionClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(ReconstructionClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionPMP = new QAction(ReconstructionClass);
        actionPMP->setObjectName(QStringLiteral("actionPMP"));
        centralWidget = new QWidget(ReconstructionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelStatus = new QLabel(centralWidget);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));
        labelStatus->setGeometry(QRect(1, 851, 1400, 21));
        labelStatus->setFont(font);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 231, 431));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        toolBox = new QToolBox(frame);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(0, 40, 231, 391));
        toolBox->setAutoFillBackground(false);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 231, 319));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_2->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_2->addWidget(pushButton_5, 4, 0, 1, 1);

        pushButton_6 = new QPushButton(page);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout_2->addWidget(pushButton_6, 5, 0, 1, 1);

        toolBox->addItem(page, QStringLiteral("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 231, 319));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_7 = new QPushButton(page_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_3->addWidget(pushButton_7, 0, 0, 1, 1);

        toolBox->addItem(page_2, QStringLiteral("Page 2"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 0, 121, 31));
        QFont font1;
        font1.setPointSize(10);
        label->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(530, 450, 191, 16));
        label_2->setFont(font1);
        label_2->setLayoutDirection(Qt::LeftToRight);
        tabWidget1 = new QTabWidget(centralWidget);
        tabWidget1->setObjectName(QStringLiteral("tabWidget1"));
        tabWidget1->setGeometry(QRect(300, 40, 660, 380));
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        labelImg1_1 = new QLabel(tab_7);
        labelImg1_1->setObjectName(QStringLiteral("labelImg1_1"));
        labelImg1_1->setGeometry(QRect(30, 0, 600, 340));
        tabWidget1->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        labelImg1_2 = new QLabel(tab_8);
        labelImg1_2->setObjectName(QStringLiteral("labelImg1_2"));
        labelImg1_2->setGeometry(QRect(30, 0, 600, 340));
        tabWidget1->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        labelImg1_3 = new QLabel(tab_9);
        labelImg1_3->setObjectName(QStringLiteral("labelImg1_3"));
        labelImg1_3->setGeometry(QRect(30, 0, 600, 340));
        tabWidget1->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        labelImg1_4 = new QLabel(tab_10);
        labelImg1_4->setObjectName(QStringLiteral("labelImg1_4"));
        labelImg1_4->setGeometry(QRect(30, 0, 600, 340));
        tabWidget1->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        labelImg1_5 = new QLabel(tab_11);
        labelImg1_5->setObjectName(QStringLiteral("labelImg1_5"));
        labelImg1_5->setGeometry(QRect(30, 0, 600, 340));
        tabWidget1->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QStringLiteral("tab_12"));
        labelImg1_6 = new QLabel(tab_12);
        labelImg1_6->setObjectName(QStringLiteral("labelImg1_6"));
        labelImg1_6->setGeometry(QRect(30, 0, 600, 340));
        tabWidget1->addTab(tab_12, QString());
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(530, 10, 191, 16));
        label_3->setFont(font1);
        label_3->setLayoutDirection(Qt::LeftToRight);
        tabWidget2 = new QTabWidget(centralWidget);
        tabWidget2->setObjectName(QStringLiteral("tabWidget2"));
        tabWidget2->setGeometry(QRect(300, 480, 660, 380));
        tab_14 = new QWidget();
        tab_14->setObjectName(QStringLiteral("tab_14"));
        labelImg2_1 = new QLabel(tab_14);
        labelImg2_1->setObjectName(QStringLiteral("labelImg2_1"));
        labelImg2_1->setGeometry(QRect(30, 0, 600, 340));
        tabWidget2->addTab(tab_14, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName(QStringLiteral("tab_15"));
        labelImg2_2 = new QLabel(tab_15);
        labelImg2_2->setObjectName(QStringLiteral("labelImg2_2"));
        labelImg2_2->setGeometry(QRect(30, 0, 600, 340));
        tabWidget2->addTab(tab_15, QString());
        tab_16 = new QWidget();
        tab_16->setObjectName(QStringLiteral("tab_16"));
        labelImg2_3 = new QLabel(tab_16);
        labelImg2_3->setObjectName(QStringLiteral("labelImg2_3"));
        labelImg2_3->setGeometry(QRect(30, 0, 600, 340));
        tabWidget2->addTab(tab_16, QString());
        tab_17 = new QWidget();
        tab_17->setObjectName(QStringLiteral("tab_17"));
        labelImg2_4 = new QLabel(tab_17);
        labelImg2_4->setObjectName(QStringLiteral("labelImg2_4"));
        labelImg2_4->setGeometry(QRect(30, 0, 600, 340));
        tabWidget2->addTab(tab_17, QString());
        tab_18 = new QWidget();
        tab_18->setObjectName(QStringLiteral("tab_18"));
        labelImg2_5 = new QLabel(tab_18);
        labelImg2_5->setObjectName(QStringLiteral("labelImg2_5"));
        labelImg2_5->setGeometry(QRect(30, 0, 600, 340));
        tabWidget2->addTab(tab_18, QString());
        tab_19 = new QWidget();
        tab_19->setObjectName(QStringLiteral("tab_19"));
        labelImg2_6 = new QLabel(tab_19);
        labelImg2_6->setObjectName(QStringLiteral("labelImg2_6"));
        labelImg2_6->setGeometry(QRect(30, 0, 600, 340));
        tabWidget2->addTab(tab_19, QString());
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(1160, 450, 72, 15));
        label_4->setFont(font1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1150, 10, 111, 16));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(980, 40, 451, 381));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(1190, 540, 171, 31));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1030, 550, 151, 16));
        label_6->setFont(font1);
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(1190, 590, 171, 31));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(1030, 600, 141, 16));
        label_7->setFont(font1);
        textEdit_3 = new QTextEdit(centralWidget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(1190, 640, 171, 31));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(990, 650, 181, 20));
        label_8->setFont(font1);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(1230, 850, 181, 31));
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(250, 60, 20, 331));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        ReconstructionClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ReconstructionClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1440, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuswitchTo = new QMenu(menuBar);
        menuswitchTo->setObjectName(QStringLiteral("menuswitchTo"));
        ReconstructionClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ReconstructionClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ReconstructionClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ReconstructionClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setAutoFillBackground(true);
        statusBar->setStyleSheet(QString::fromUtf8("font: 25 9pt \".\350\213\271\346\226\271-\347\256\200\";"));
        ReconstructionClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuswitchTo->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuswitchTo->addAction(actionPMP);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSave);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPMP);

        retranslateUi(ReconstructionClass);

        toolBox->setCurrentIndex(0);
        tabWidget1->setCurrentIndex(0);
        tabWidget2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ReconstructionClass);
    } // setupUi

    void retranslateUi(QMainWindow *ReconstructionClass)
    {
        ReconstructionClass->setWindowTitle(QApplication::translate("ReconstructionClass", "3D-Reconstruction", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("ReconstructionClass", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("ReconstructionClass", "Save", Q_NULLPTR));
        actionPMP->setText(QApplication::translate("ReconstructionClass", "PMP", Q_NULLPTR));
        labelStatus->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ReconstructionClass", "\346\273\244\346\263\242", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("ReconstructionClass", "\347\246\273\346\225\243\345\202\205\351\207\214\345\217\266\345\217\215\345\217\230\346\215\242", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ReconstructionClass", "\347\246\273\346\225\243\345\202\205\351\207\214\345\217\266\345\217\230\346\215\242", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("ReconstructionClass", "\346\261\202\347\233\270\344\275\215", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("ReconstructionClass", "\350\247\243\347\233\270\344\275\215", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("ReconstructionClass", "\351\207\215\345\273\272\344\270\211\347\273\264\346\250\241\345\236\213", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("ReconstructionClass", "Page 1", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("ReconstructionClass", "One Step", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("ReconstructionClass", "Page 2", Q_NULLPTR));
        label->setText(QApplication::translate("ReconstructionClass", "\345\233\276\345\203\217\345\244\204\347\220\206\346\223\215\344\275\234", Q_NULLPTR));
        label_2->setText(QApplication::translate("ReconstructionClass", "\350\260\203\345\210\266\345\205\211\346\240\205\345\233\276\345\203\217\345\244\204\347\220\206\347\273\223\346\236\234", Q_NULLPTR));
        labelImg1_1->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_7), QApplication::translate("ReconstructionClass", "\345\216\237\345\233\276", Q_NULLPTR));
        labelImg1_2->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_8), QApplication::translate("ReconstructionClass", "\351\242\221\345\237\237\345\233\276\345\203\217", Q_NULLPTR));
        labelImg1_3->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_9), QApplication::translate("ReconstructionClass", "\346\273\244\346\263\242\345\220\216\351\242\221\345\237\237\345\233\276\345\203\217", Q_NULLPTR));
        labelImg1_4->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_10), QApplication::translate("ReconstructionClass", "\346\273\244\346\263\242\345\220\216\347\251\272\345\237\237\345\233\276\345\203\217", Q_NULLPTR));
        labelImg1_5->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_11), QApplication::translate("ReconstructionClass", "\345\214\205\350\243\271\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        labelImg1_6->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_12), QApplication::translate("ReconstructionClass", "\350\247\243\345\214\205\350\243\271\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        label_3->setText(QApplication::translate("ReconstructionClass", "\345\217\202\350\200\203\345\271\263\351\235\242\345\233\276\345\203\217\345\244\204\347\220\206\347\273\223\346\236\234", Q_NULLPTR));
        labelImg2_1->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget2->setTabText(tabWidget2->indexOf(tab_14), QApplication::translate("ReconstructionClass", "\345\216\237\345\233\276", Q_NULLPTR));
        labelImg2_2->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget2->setTabText(tabWidget2->indexOf(tab_15), QApplication::translate("ReconstructionClass", "\351\242\221\345\237\237\345\233\276\345\203\217", Q_NULLPTR));
        labelImg2_3->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget2->setTabText(tabWidget2->indexOf(tab_16), QApplication::translate("ReconstructionClass", "\346\273\244\346\263\242\345\220\216\351\242\221\345\237\237\345\233\276\345\203\217", Q_NULLPTR));
        labelImg2_4->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget2->setTabText(tabWidget2->indexOf(tab_17), QApplication::translate("ReconstructionClass", "\346\273\244\346\263\242\345\220\216\347\251\272\345\237\237\345\233\276\345\203\217", Q_NULLPTR));
        labelImg2_5->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget2->setTabText(tabWidget2->indexOf(tab_18), QApplication::translate("ReconstructionClass", "\345\214\205\350\243\271\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        labelImg2_6->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget2->setTabText(tabWidget2->indexOf(tab_19), QApplication::translate("ReconstructionClass", "\350\247\243\345\214\205\350\243\271\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        label_4->setText(QApplication::translate("ReconstructionClass", "\346\225\260\346\215\256\346\230\276\347\244\272", Q_NULLPTR));
        label_5->setText(QApplication::translate("ReconstructionClass", "\346\225\260\346\215\256\347\273\237\350\256\241", Q_NULLPTR));
        label_6->setText(QApplication::translate("ReconstructionClass", "\345\275\223\345\211\215\347\202\271\345\235\220\346\240\207(mm)\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("ReconstructionClass", "\345\275\223\345\211\215\347\202\271\351\253\230\345\272\246(mm)\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("ReconstructionClass", "\345\276\205\346\265\213\347\211\251\344\275\223\344\275\223\347\247\257(mm^3)\357\274\232", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("ReconstructionClass", "File", Q_NULLPTR));
        menuswitchTo->setTitle(QApplication::translate("ReconstructionClass", "SwitchTo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReconstructionClass: public Ui_ReconstructionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECONSTRUCTION_H
