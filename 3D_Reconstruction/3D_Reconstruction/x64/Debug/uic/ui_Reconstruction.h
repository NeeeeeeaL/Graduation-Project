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
#include <QtWidgets/QComboBox>
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
    QComboBox *comboBox;
    QTabWidget *tabWidget1;
    QWidget *tab_7;
    QLabel *labelImg1_1;
    QLabel *labelImg2_1;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget;
    QWidget *tab_8;
    QLabel *labelImg1_2;
    QLabel *labelImg2_2;
    QWidget *tab_9;
    QLabel *labelImg1_3;
    QLabel *labelImg2_3;
    QWidget *tab_10;
    QLabel *labelImg1_4;
    QLabel *labelImg2_4;
    QWidget *tab_11;
    QLabel *labelImg1_5;
    QLabel *labelImg2_5;
    QWidget *tab_12;
    QLabel *labelImg1_6;
    QLabel *labelImg2_6;
    QLabel *label_3;
    QProgressBar *progressBar;
    QLabel *label_9;
    QLabel *labelGetImg;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuswitchTo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ReconstructionClass)
    {
        if (ReconstructionClass->objectName().isEmpty())
            ReconstructionClass->setObjectName(QStringLiteral("ReconstructionClass"));
        ReconstructionClass->resize(1800, 960);
        ReconstructionClass->setMaximumSize(QSize(1800, 960));
        QFont font;
        font.setFamily(QString::fromUtf8(".\350\213\271\346\226\271-\347\256\200"));
        ReconstructionClass->setFont(font);
        ReconstructionClass->setMouseTracking(true);
        ReconstructionClass->setAutoFillBackground(false);
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
        frame->setFont(font);
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        toolBox = new QToolBox(frame);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(0, 120, 201, 311));
        toolBox->setFont(font);
        toolBox->setAutoFillBackground(false);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 201, 239));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFont(font);

        gridLayout_2->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setFont(font);

        gridLayout_2->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setFont(font);

        gridLayout_2->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_5 = new QPushButton(page);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setFont(font);

        gridLayout_2->addWidget(pushButton_5, 4, 0, 1, 1);

        pushButton_6 = new QPushButton(page);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setFont(font);

        gridLayout_2->addWidget(pushButton_6, 5, 0, 1, 1);

        toolBox->addItem(page, QStringLiteral("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 201, 239));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_7 = new QPushButton(page_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setStyleSheet(QStringLiteral(""));

        gridLayout_3->addWidget(pushButton_7, 0, 0, 1, 1);

        toolBox->addItem(page_2, QStringLiteral("Page 2"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 80, 121, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8(".\350\213\271\346\226\271-\347\256\200"));
        font1.setPointSize(10);
        label->setFont(font1);
        comboBox = new QComboBox(frame);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(40, 20, 165, 35));
        comboBox->setMinimumSize(QSize(135, 0));
        comboBox->setFont(font1);
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
"\n"
"\n"
""));
        tabWidget1 = new QTabWidget(centralWidget);
        tabWidget1->setObjectName(QStringLiteral("tabWidget1"));
        tabWidget1->setGeometry(QRect(250, 40, 1520, 800));
        tabWidget1->setFont(font);
        tabWidget1->setContextMenuPolicy(Qt::DefaultContextMenu);
        tabWidget1->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QTabWidget::tab-bar{ alignment: center;}\n"
"QTabBar::tab:selected{ background-color: rgb(0, 122, 255);color: white; }\n"
"\n"
"QTabBar::tab{ width: 120px; height:25px; border-radius: 4px; margin-bottom: 6px;}\342\200\213\n"
"\n"
""));
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        QFont font2;
        tab_7->setFont(font2);
        labelImg1_1 = new QLabel(tab_7);
        labelImg1_1->setObjectName(QStringLiteral("labelImg1_1"));
        labelImg1_1->setGeometry(QRect(0, 0, 750, 720));
        labelImg1_1->setFont(font);
        labelImg2_1 = new QLabel(tab_7);
        labelImg2_1->setObjectName(QStringLiteral("labelImg2_1"));
        labelImg2_1->setGeometry(QRect(770, 0, 750, 720));
        labelImg2_1->setFont(font);
        label_4 = new QLabel(tab_7);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(335, 730, 81, 16));
        label_4->setFont(font);
        label_5 = new QLabel(tab_7);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1100, 730, 91, 16));
        label_5->setFont(font);
        widget = new QWidget(tab_7);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-20, 70, 1531, 831));
        tabWidget1->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        labelImg1_2 = new QLabel(tab_8);
        labelImg1_2->setObjectName(QStringLiteral("labelImg1_2"));
        labelImg1_2->setGeometry(QRect(30, 0, 531, 751));
        labelImg1_2->setFont(font);
        labelImg2_2 = new QLabel(tab_8);
        labelImg2_2->setObjectName(QStringLiteral("labelImg2_2"));
        labelImg2_2->setGeometry(QRect(599, 20, 541, 721));
        labelImg2_2->setFont(font);
        tabWidget1->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        labelImg1_3 = new QLabel(tab_9);
        labelImg1_3->setObjectName(QStringLiteral("labelImg1_3"));
        labelImg1_3->setGeometry(QRect(30, 0, 511, 741));
        labelImg1_3->setFont(font);
        labelImg2_3 = new QLabel(tab_9);
        labelImg2_3->setObjectName(QStringLiteral("labelImg2_3"));
        labelImg2_3->setGeometry(QRect(600, 10, 541, 731));
        labelImg2_3->setFont(font);
        tabWidget1->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        labelImg1_4 = new QLabel(tab_10);
        labelImg1_4->setObjectName(QStringLiteral("labelImg1_4"));
        labelImg1_4->setGeometry(QRect(30, 0, 541, 741));
        labelImg1_4->setFont(font);
        labelImg2_4 = new QLabel(tab_10);
        labelImg2_4->setObjectName(QStringLiteral("labelImg2_4"));
        labelImg2_4->setGeometry(QRect(620, 10, 521, 741));
        labelImg2_4->setFont(font);
        tabWidget1->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        labelImg1_5 = new QLabel(tab_11);
        labelImg1_5->setObjectName(QStringLiteral("labelImg1_5"));
        labelImg1_5->setGeometry(QRect(10, 0, 571, 731));
        labelImg1_5->setFont(font);
        labelImg2_5 = new QLabel(tab_11);
        labelImg2_5->setObjectName(QStringLiteral("labelImg2_5"));
        labelImg2_5->setGeometry(QRect(590, 10, 541, 711));
        labelImg2_5->setFont(font);
        tabWidget1->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QStringLiteral("tab_12"));
        labelImg1_6 = new QLabel(tab_12);
        labelImg1_6->setObjectName(QStringLiteral("labelImg1_6"));
        labelImg1_6->setGeometry(QRect(30, 0, 691, 731));
        labelImg1_6->setFont(font);
#ifndef QT_NO_STATUSTIP
        labelImg1_6->setStatusTip(QStringLiteral(""));
#endif // QT_NO_STATUSTIP
        labelImg1_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelImg2_6 = new QLabel(tab_12);
        labelImg2_6->setObjectName(QStringLiteral("labelImg2_6"));
        labelImg2_6->setGeometry(QRect(780, 10, 711, 731));
        labelImg2_6->setFont(font);
        tabWidget1->addTab(tab_12, QString());
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(935, 10, 171, 16));
        label_3->setFont(font1);
        label_3->setLayoutDirection(Qt::LeftToRight);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(1220, 860, 181, 31));
        progressBar->setFont(font);
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(80, 450, 71, 31));
        label_9->setFont(font1);
        labelGetImg = new QLabel(centralWidget);
        labelGetImg->setObjectName(QStringLiteral("labelGetImg"));
        labelGetImg->setGeometry(QRect(10, 500, 251, 211));
        labelGetImg->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 730, 231, 101));
        layoutWidget->setFont(font);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setFont(font);

        gridLayout->addWidget(pushButton_8, 0, 0, 1, 1);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setFont(font);

        gridLayout->addWidget(pushButton_9, 0, 1, 1, 1);

        pushButton_10 = new QPushButton(layoutWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setFont(font);

        gridLayout->addWidget(pushButton_10, 1, 0, 1, 1);

        pushButton_11 = new QPushButton(layoutWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setFont(font);

        gridLayout->addWidget(pushButton_11, 1, 1, 1, 1);

        ReconstructionClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ReconstructionClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1800, 26));
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
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ReconstructionClass", "\347\263\273\347\273\237\346\240\207\345\256\232", Q_NULLPTR)
         << QApplication::translate("ReconstructionClass", "\345\233\276\345\203\217\345\244\204\347\220\206", Q_NULLPTR)
         << QApplication::translate("ReconstructionClass", "\344\270\211\347\273\264\351\207\215\345\273\272\351\242\204\350\247\210", Q_NULLPTR)
         << QApplication::translate("ReconstructionClass", "\347\273\237\350\256\241\344\270\216\345\210\206\346\236\220", Q_NULLPTR)
        );
        labelImg1_1->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        labelImg2_1->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("ReconstructionClass", "\345\216\237\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("ReconstructionClass", "\350\260\203\345\210\266\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_7), QApplication::translate("ReconstructionClass", "\345\216\237\345\233\276", Q_NULLPTR));
        labelImg1_2->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        labelImg2_2->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_8), QApplication::translate("ReconstructionClass", "\351\242\221\345\237\237\345\233\276\345\203\217", Q_NULLPTR));
        labelImg1_3->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        labelImg2_3->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_9), QApplication::translate("ReconstructionClass", "\346\273\244\346\263\242\345\220\216\351\242\221\345\237\237\345\233\276\345\203\217", Q_NULLPTR));
        labelImg1_4->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        labelImg2_4->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_10), QApplication::translate("ReconstructionClass", "\346\273\244\346\263\242\345\220\216\347\251\272\345\237\237\345\233\276\345\203\217", Q_NULLPTR));
        labelImg1_5->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        labelImg2_5->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_11), QApplication::translate("ReconstructionClass", "\345\214\205\350\243\271\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        labelImg1_6->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        labelImg2_6->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_12), QApplication::translate("ReconstructionClass", "\350\247\243\345\214\205\350\243\271\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        label_3->setText(QApplication::translate("ReconstructionClass", "\345\217\202\350\200\203\345\271\263\351\235\242\345\233\276\345\203\217\345\244\204\347\220\206\347\273\223\346\236\234", Q_NULLPTR));
        label_9->setText(QApplication::translate("ReconstructionClass", "\345\233\276\345\203\217\351\207\207\351\233\206", Q_NULLPTR));
        labelGetImg->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("ReconstructionClass", "\345\215\225\345\270\247\351\207\207\351\233\206", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("ReconstructionClass", "\350\277\236\347\273\255\351\207\207\351\233\206", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("ReconstructionClass", "\345\201\234\346\255\242\351\207\207\351\233\206", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("ReconstructionClass", "\344\277\235\345\255\230", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("ReconstructionClass", "File", Q_NULLPTR));
        menuswitchTo->setTitle(QApplication::translate("ReconstructionClass", "SwitchTo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReconstructionClass: public Ui_ReconstructionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECONSTRUCTION_H
