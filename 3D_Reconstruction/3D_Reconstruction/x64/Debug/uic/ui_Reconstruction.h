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
#include <QtWidgets/QSlider>
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
    QTabWidget *tabWidget1;
    QWidget *tab_7;
    QLabel *labelImg1_1;
    QLabel *labelImg2_1;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *tab_8;
    QLabel *labelImg1_2;
    QLabel *labelImg2_2;
    QLabel *label_8;
    QLabel *label_10;
    QWidget *tab_9;
    QLabel *labelImg1_3;
    QLabel *labelImg2_3;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *tab_10;
    QLabel *labelImg1_4;
    QLabel *labelImg2_4;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *tab_11;
    QLabel *labelImg1_5;
    QLabel *labelImg2_5;
    QLabel *label_15;
    QLabel *label_16;
    QWidget *tab_12;
    QLabel *labelImg1_6;
    QLabel *labelImg2_6;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_3;
    QProgressBar *progressBar;
    QLabel *label_9;
    QLabel *labelGetImg;
    QComboBox *comboBox;
    QLabel *label;
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
    QLabel *label_6;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
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
        ReconstructionClass->setStyleSheet(QStringLiteral("QMainWindow{background-color: white;}"));
        ReconstructionClass->setAnimated(true);
        actionOpen = new QAction(ReconstructionClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen->setFont(font);
        actionSave = new QAction(ReconstructionClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setFont(font);
        actionPMP = new QAction(ReconstructionClass);
        actionPMP->setObjectName(QStringLiteral("actionPMP"));
        actionPMP->setFont(font);
        centralWidget = new QWidget(ReconstructionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelStatus = new QLabel(centralWidget);
        labelStatus->setObjectName(QStringLiteral("labelStatus"));
        labelStatus->setGeometry(QRect(1, 851, 1400, 21));
        labelStatus->setFont(font);
        tabWidget1 = new QTabWidget(centralWidget);
        tabWidget1->setObjectName(QStringLiteral("tabWidget1"));
        tabWidget1->setGeometry(QRect(250, 40, 1520, 800));
        tabWidget1->setFont(font);
        tabWidget1->setContextMenuPolicy(Qt::DefaultContextMenu);
        tabWidget1->setAutoFillBackground(false);
        tabWidget1->setStyleSheet(QString::fromUtf8("QTabWidget::tab-bar{ alignment: center;}\n"
"QTabBar::tab:selected{ background-color: rgb(0, 122, 255);color: white; }\n"
"\n"
"QTabBar::tab{ width: 120px; height:25px; border-radius: 4px; margin-bottom: 6px;}\342\200\213\n"
"\n"
""));
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        QFont font1;
        tab_7->setFont(font1);
        labelImg1_1 = new QLabel(tab_7);
        labelImg1_1->setObjectName(QStringLiteral("labelImg1_1"));
        labelImg1_1->setGeometry(QRect(0, 0, 750, 720));
        labelImg1_1->setFont(font);
        labelImg1_1->setAutoFillBackground(false);
        labelImg1_1->setStyleSheet(QStringLiteral(""));
        labelImg2_1 = new QLabel(tab_7);
        labelImg2_1->setObjectName(QStringLiteral("labelImg2_1"));
        labelImg2_1->setGeometry(QRect(770, 0, 750, 720));
        labelImg2_1->setFont(font);
        labelImg2_1->setStyleSheet(QStringLiteral(""));
        label_4 = new QLabel(tab_7);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(335, 730, 81, 16));
        label_4->setFont(font);
        label_5 = new QLabel(tab_7);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(1100, 730, 91, 16));
        label_5->setFont(font);
        tabWidget1->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        labelImg1_2 = new QLabel(tab_8);
        labelImg1_2->setObjectName(QStringLiteral("labelImg1_2"));
        labelImg1_2->setGeometry(QRect(0, 0, 750, 720));
        labelImg1_2->setFont(font);
        labelImg2_2 = new QLabel(tab_8);
        labelImg2_2->setObjectName(QStringLiteral("labelImg2_2"));
        labelImg2_2->setGeometry(QRect(770, 0, 750, 720));
        labelImg2_2->setFont(font);
        label_8 = new QLabel(tab_8);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1100, 730, 91, 16));
        label_8->setFont(font);
        label_10 = new QLabel(tab_8);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(335, 730, 81, 16));
        label_10->setFont(font);
        tabWidget1->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        labelImg1_3 = new QLabel(tab_9);
        labelImg1_3->setObjectName(QStringLiteral("labelImg1_3"));
        labelImg1_3->setGeometry(QRect(0, 0, 750, 720));
        labelImg1_3->setFont(font);
        labelImg2_3 = new QLabel(tab_9);
        labelImg2_3->setObjectName(QStringLiteral("labelImg2_3"));
        labelImg2_3->setGeometry(QRect(770, 0, 750, 720));
        labelImg2_3->setFont(font);
        label_11 = new QLabel(tab_9);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(1100, 730, 91, 16));
        label_11->setFont(font);
        label_12 = new QLabel(tab_9);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(335, 730, 81, 16));
        label_12->setFont(font);
        tabWidget1->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        labelImg1_4 = new QLabel(tab_10);
        labelImg1_4->setObjectName(QStringLiteral("labelImg1_4"));
        labelImg1_4->setGeometry(QRect(0, 0, 750, 720));
        labelImg1_4->setFont(font);
        labelImg2_4 = new QLabel(tab_10);
        labelImg2_4->setObjectName(QStringLiteral("labelImg2_4"));
        labelImg2_4->setGeometry(QRect(770, 0, 750, 720));
        labelImg2_4->setFont(font);
        label_13 = new QLabel(tab_10);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(1100, 730, 91, 16));
        label_13->setFont(font);
        label_14 = new QLabel(tab_10);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(335, 730, 81, 16));
        label_14->setFont(font);
        tabWidget1->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        labelImg1_5 = new QLabel(tab_11);
        labelImg1_5->setObjectName(QStringLiteral("labelImg1_5"));
        labelImg1_5->setGeometry(QRect(0, 0, 750, 720));
        labelImg1_5->setFont(font);
        labelImg2_5 = new QLabel(tab_11);
        labelImg2_5->setObjectName(QStringLiteral("labelImg2_5"));
        labelImg2_5->setGeometry(QRect(770, 0, 750, 720));
        labelImg2_5->setFont(font);
        label_15 = new QLabel(tab_11);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(1100, 730, 91, 16));
        label_15->setFont(font);
        label_16 = new QLabel(tab_11);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(335, 730, 81, 16));
        label_16->setFont(font);
        tabWidget1->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QStringLiteral("tab_12"));
        labelImg1_6 = new QLabel(tab_12);
        labelImg1_6->setObjectName(QStringLiteral("labelImg1_6"));
        labelImg1_6->setGeometry(QRect(0, 0, 750, 720));
        labelImg1_6->setFont(font);
#ifndef QT_NO_STATUSTIP
        labelImg1_6->setStatusTip(QStringLiteral(""));
#endif // QT_NO_STATUSTIP
        labelImg1_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelImg2_6 = new QLabel(tab_12);
        labelImg2_6->setObjectName(QStringLiteral("labelImg2_6"));
        labelImg2_6->setGeometry(QRect(770, 0, 750, 720));
        labelImg2_6->setFont(font);
        label_17 = new QLabel(tab_12);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(1100, 730, 91, 16));
        label_17->setFont(font);
        label_18 = new QLabel(tab_12);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(335, 730, 81, 16));
        label_18->setFont(font);
        tabWidget1->addTab(tab_12, QString());
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(900, 10, 211, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8(".\350\213\271\346\226\271-\347\256\200"));
        font2.setPointSize(10);
        label_3->setFont(font2);
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
        label_9->setGeometry(QRect(50, 460, 121, 31));
        label_9->setFont(font2);
        labelGetImg = new QLabel(centralWidget);
        labelGetImg->setObjectName(QStringLiteral("labelGetImg"));
        labelGetImg->setGeometry(QRect(10, 500, 231, 211));
        labelGetImg->setFont(font);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(84, 20, 165, 35));
        comboBox->setMinimumSize(QSize(141, 0));
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
"\n"
"\n"
""));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 80, 121, 31));
        label->setFont(font2);
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(10, 120, 201, 311));
        toolBox->setFont(font);
        toolBox->setAutoFillBackground(false);
        toolBox->setStyleSheet(QStringLiteral(" QToolBox::tab {padding-left: 70px;}"));
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
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QStringLiteral(""));

        gridLayout_3->addWidget(pushButton_7, 1, 0, 1, 1);

        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QLatin1String("QLabel{border-image: url(:/Reconstruction/Resources/step.ico)}\n"
""));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        toolBox->addItem(page_2, QStringLiteral("Page 2"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(240, 69, 20, 821));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(-3, 60, 1811, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(15, 10, 50, 50));
        label_2->setStyleSheet(QStringLiteral("QLabel{border-image: url(:/Reconstruction/Resources/myico.ico)}"));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 770, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(170, 640, 22, 91));
        verticalSlider->setOrientation(Qt::Vertical);
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
        mainToolBar->setFont(font1);
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

        tabWidget1->setCurrentIndex(1);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ReconstructionClass);
    } // setupUi

    void retranslateUi(QMainWindow *ReconstructionClass)
    {
        ReconstructionClass->setWindowTitle(QApplication::translate("ReconstructionClass", "3D-Reconstruction", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("ReconstructionClass", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("ReconstructionClass", "Save", Q_NULLPTR));
        actionPMP->setText(QApplication::translate("ReconstructionClass", "PMP", Q_NULLPTR));
        labelStatus->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        labelImg1_1->setText(QString());
        labelImg2_1->setText(QString());
        label_4->setText(QApplication::translate("ReconstructionClass", "\345\216\237\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("ReconstructionClass", "\350\260\203\345\210\266\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_7), QApplication::translate("ReconstructionClass", "\345\216\237\345\233\276", Q_NULLPTR));
        labelImg1_2->setText(QString());
        labelImg2_2->setText(QString());
        label_8->setText(QApplication::translate("ReconstructionClass", "\350\260\203\345\210\266\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        label_10->setText(QApplication::translate("ReconstructionClass", "\345\216\237\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_8), QApplication::translate("ReconstructionClass", "\351\242\221\345\237\237\345\233\276\345\203\217", Q_NULLPTR));
        labelImg1_3->setText(QString());
        labelImg2_3->setText(QString());
        label_11->setText(QApplication::translate("ReconstructionClass", "\350\260\203\345\210\266\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        label_12->setText(QApplication::translate("ReconstructionClass", "\345\216\237\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_9), QApplication::translate("ReconstructionClass", "\346\273\244\346\263\242\345\220\216\351\242\221\345\237\237\345\233\276\345\203\217", Q_NULLPTR));
        labelImg1_4->setText(QString());
        labelImg2_4->setText(QString());
        label_13->setText(QApplication::translate("ReconstructionClass", "\350\260\203\345\210\266\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        label_14->setText(QApplication::translate("ReconstructionClass", "\345\216\237\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_10), QApplication::translate("ReconstructionClass", "\346\273\244\346\263\242\345\220\216\347\251\272\345\237\237\345\233\276\345\203\217", Q_NULLPTR));
        labelImg1_5->setText(QString());
        labelImg2_5->setText(QString());
        label_15->setText(QApplication::translate("ReconstructionClass", "\350\260\203\345\210\266\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        label_16->setText(QApplication::translate("ReconstructionClass", "\345\216\237\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_11), QApplication::translate("ReconstructionClass", "\345\214\205\350\243\271\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        labelImg1_6->setText(QString());
        labelImg2_6->setText(QString());
        label_17->setText(QApplication::translate("ReconstructionClass", "\350\260\203\345\210\266\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        label_18->setText(QApplication::translate("ReconstructionClass", "\345\216\237\345\205\211\346\240\205\345\233\276\345\203\217", Q_NULLPTR));
        tabWidget1->setTabText(tabWidget1->indexOf(tab_12), QApplication::translate("ReconstructionClass", "\350\247\243\345\214\205\350\243\271\347\233\270\344\275\215\345\233\276", Q_NULLPTR));
        label_3->setText(QApplication::translate("ReconstructionClass", "\345\202\205\351\207\214\345\217\266\350\275\256\345\273\223\346\234\257\345\233\276\345\203\217\345\244\204\347\220\206\347\273\223\346\236\234", Q_NULLPTR));
        label_9->setText(QApplication::translate("ReconstructionClass", "\346\273\244\346\263\242\345\231\250\345\217\202\346\225\260\350\260\203\350\212\202", Q_NULLPTR));
        labelGetImg->setText(QApplication::translate("ReconstructionClass", "TextLabel", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ReconstructionClass", "\347\263\273\347\273\237\346\240\207\345\256\232", Q_NULLPTR)
         << QApplication::translate("ReconstructionClass", "\345\233\276\345\203\217\345\244\204\347\220\206", Q_NULLPTR)
         << QApplication::translate("ReconstructionClass", "\344\270\211\347\273\264\346\250\241\345\236\213\351\242\204\350\247\210", Q_NULLPTR)
         << QApplication::translate("ReconstructionClass", "\347\273\237\350\256\241\344\270\216\345\210\206\346\236\220", Q_NULLPTR)
        );
        label->setText(QApplication::translate("ReconstructionClass", "\345\233\276\345\203\217\345\244\204\347\220\206\346\223\215\344\275\234", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ReconstructionClass", "\346\273\244\346\263\242", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("ReconstructionClass", "\347\246\273\346\225\243\345\202\205\351\207\214\345\217\266\345\217\215\345\217\230\346\215\242", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ReconstructionClass", "\347\246\273\346\225\243\345\202\205\351\207\214\345\217\266\345\217\230\346\215\242", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("ReconstructionClass", "\346\261\202\347\233\270\344\275\215", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("ReconstructionClass", "\350\247\243\347\233\270\344\275\215", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("ReconstructionClass", "\351\207\215\345\273\272\344\270\211\347\273\264\346\250\241\345\236\213", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("ReconstructionClass", "Page 1", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("ReconstructionClass", "One Step", Q_NULLPTR));
        label_6->setText(QString());
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("ReconstructionClass", "Page 2", Q_NULLPTR));
        label_2->setText(QString());
        menuFile->setTitle(QApplication::translate("ReconstructionClass", "File", Q_NULLPTR));
        menuswitchTo->setTitle(QApplication::translate("ReconstructionClass", "SwitchTo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ReconstructionClass: public Ui_ReconstructionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECONSTRUCTION_H
