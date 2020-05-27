#include "pmpTrans.h"
#include "imageProcess.h"
#include "unwrap.h"
#include "display.h"
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QSplitter>
#include <QTextCodec> //转换字符头文件

#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"
QTextCodec *codecChild;

using namespace std;


PMPTrans::PMPTrans(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//初始化codec
	codecChild = QTextCodec::codecForName("GBK");

	this->setWindowIcon(QIcon("myico.ico"));
	this->setWindowTitle("PMP Translation");
	statusBar()->setStyleSheet(QString("QStatusBar::item{border: 0px}")); // 设置不显示label的边框
	statusBar()->setSizeGripEnabled(false); //设置是否显示右边的大小控制点
	statusBar()->addWidget(ui.labelStatus, 4);
	statusBar()->addWidget(ui.progressBar, 1);
	ui.labelStatus->setText("Ready");
	ui.progressBar->setVisible(true);
	ui.progressBar->setMinimum(0);
	ui.progressBar->setMaximum(100);
	ui.progressBar->reset();

	QIcon iconOpen("Resources//openImage.ico");
	QIcon iconSave("Resources//save.ico");
	QIcon iconSwitch("Resources//switchRight.ico");

	QIcon icon0("Resources//imageProcess.ico");
	QIcon icon1("Resources//cube.ico");

	ui.actionOpen->setIcon(iconOpen);
	ui.actionSave->setIcon(iconSave);
	ui.actionFTP->setIcon(iconSwitch);

	ui.comboBox->setItemIcon(0, icon0);
	ui.comboBox->setItemIcon(1, icon1);

	//将窗口移动到合适的位置
	this->move(50, 45);

	//设置TabWidget的初始Tab
	ui.tabWidget->setCurrentIndex(0);
}

PMPTrans::~PMPTrans()
{
}

//在QLabel上显示Mat图像
void PMPTrans::LabelDisplayMat(cv::Mat & mat_img, QLabel * label)
{
	QImage img;
	if (mat_img.channels() == 3)//RGB image
	{
		cvtColor(mat_img, mat_img, CV_BGR2RGB); //Mat:BGR  //QImage:RGB
		img = QImage((const unsigned char*)(mat_img.data), mat_img.cols, mat_img.rows,
			mat_img.cols * mat_img.channels(), QImage::Format_RGB888);
	}
	else//Gray image
	{
		img = QImage((const unsigned char*)(mat_img.data), mat_img.cols, mat_img.rows,
			mat_img.cols * mat_img.channels(), QImage::Format_Indexed8);
	}
	QPixmap pixmap = QPixmap::fromImage(img);
	//QPixmap fitpixmap = pixmap.scaled(label->width(), label->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation); //饱满填充
	QPixmap fitpixmap = pixmap.scaled(label->width(), label->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation); //等比例填充
	label->setPixmap(fitpixmap);
	label->setAlignment(Qt::AlignCenter);//图片居中显示

}

void PMPTrans::on_actionOpen_triggered()
{
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(on_actionOpen_triggered));

	//打开原图像
	QStringList pathList = QFileDialog::getOpenFileNames(this, "open", "../");//打开所有文件

	//状态栏显示
	ui.statusBar->showMessage("Openning file... ", 1500);

	for (int i = 0; i < pathList.size(); ++i)
	{
		if (false == pathList[i].isEmpty())
		{
			//定义QFile对象
			QFile file(pathList[i]);

			//定义QFileInfo对象，获取文件名
			QFileInfo fileInfo(file);

			QString imgName = fileInfo.fileName();

			switch (i)
			{

				/***********读入四幅原光栅图像************/

			case 0: {
						imgSrc5 = cv::imread("..\\image\\phase4\\8-1.bmp", 0);//backGround3-0
						LabelDisplayMat(imgSrc5, ui.label2_1);

					}break;

			case 1: {
						imgSrc6 = cv::imread("..\\image\\phase4\\8-2.bmp", 0);
						LabelDisplayMat(imgSrc6, ui.label2_2);

					}break;

			case 2: {
						imgSrc7 = cv::imread("..\\image\\phase4\\8-3.bmp", 0);
						LabelDisplayMat(imgSrc7, ui.label2_3);

					}break;

			case 3: {
						imgSrc8 = cv::imread("..\\image\\phase4\\8-4.bmp", 0);
						LabelDisplayMat(imgSrc8, ui.label2_4);

					}break;

				/**********读入四幅调制光栅图像*************/
			case 4: {
						imgSrc1 = cv::imread("..\\image\\phase4\\8-5.bmp", 0);
						LabelDisplayMat(imgSrc1, ui.label1_1);
						
					}break;

			case 5: {
						imgSrc2 = cv::imread("..\\image\\phase4\\8-6.bmp", 0);
						LabelDisplayMat(imgSrc2, ui.label1_2);
						
					}break;

			case 6: {
						imgSrc3 = cv::imread("..\\image\\phase4\\8-7.bmp", 0);
						LabelDisplayMat(imgSrc3, ui.label1_3);
						
					}break;

			case 7: {
						imgSrc4 = cv::imread("..\\image\\phase4\\8-8.bmp", 0);
						LabelDisplayMat(imgSrc4, ui.label1_4);
						
					}break;

			default: break;
			}

		}
	}

	imgSrc1.convertTo(imgSrc1, CV_64F, 1.0 / 255.0);
	imgSrc2.convertTo(imgSrc2, CV_64F, 1.0 / 255.0);
	imgSrc3.convertTo(imgSrc3, CV_64F, 1.0 / 255.0);
	imgSrc4.convertTo(imgSrc4, CV_64F, 1.0 / 255.0);

	imgSrc5.convertTo(imgSrc5, CV_64F, 1.0 / 255.0);
	imgSrc6.convertTo(imgSrc6, CV_64F, 1.0 / 255.0);
	imgSrc7.convertTo(imgSrc7, CV_64F, 1.0 / 255.0);
	imgSrc8.convertTo(imgSrc8, CV_64F, 1.0 / 255.0);

	isOpen = true;
}

//求相位
void PMPTrans::on_pushButton1_clicked()
{
	if (isOpen == true)
	{
		ui.labelStatus->setText("Getting phase...");
		ui.progressBar->setValue(10);

		ImageProcess getP;

		phaseFG = getP.getPhase(imgSrc1, imgSrc2, imgSrc3, imgSrc4);
		phaseBG = getP.getPhase(imgSrc5, imgSrc6, imgSrc7, imgSrc8);
		ui.progressBar->setValue(20);

		/********解包裹*******/

		cv::Mat imgTmp1(imgSrc1.rows, imgSrc1.cols, CV_64F, cv::Scalar(0));
		cv::Mat imgTmp2(imgSrc1.rows, imgSrc1.cols, CV_32F, cv::Scalar(0));
		cv::Mat wrappedPhaseNormal(imgSrc1.rows, imgSrc1.cols, CV_64F, cv::Scalar(0));
		cv::Mat unwrappedPhaseNormal(imgSrc1.rows, imgSrc1.cols, CV_32F, cv::Scalar(0));
		ui.progressBar->setValue(30);
		wrappedPhase = imgTmp1;
		unwrappedPhase = imgTmp2;
		ui.progressBar->setValue(40);
		for (int i = 0; i < wrappedPhase.rows; ++i)
		{
			for (int j = 0; j < wrappedPhase.cols; ++j)
			{
				wrappedPhase.at<double>(i, j) = phaseFG.at<double>(i, j) - phaseBG.at<double>(i, j);

			}
		}
		ui.progressBar->setValue(50);
		unwrap(wrappedPhase, unwrappedPhase);

		unwrappedPhase = abs(unwrappedPhase);
		ui.progressBar->setValue(70);
		normalize(wrappedPhase, wrappedPhaseNormal, 0, 1, CV_MINMAX);
		normalize(unwrappedPhase, unwrappedPhaseNormal, 0, 1, CV_MINMAX);

		cv::Mat imgDisplay3 = wrappedPhaseNormal;
		cv::Mat imgDisplay4 = unwrappedPhaseNormal;

		for (int i = 0; i < imgDisplay3.rows; ++i)
		{
			for (int j = 0; j < imgDisplay3.cols; ++j)
			{
				imgDisplay3.at<double>(i, j) *= 255.0;
				imgDisplay4.at<float>(i, j) *= 255.0;
			}
		}
		ui.progressBar->setValue(80);
		imgDisplay4.convertTo(imgDisplay4, CV_8U);
		imgDisplay3.convertTo(imgDisplay3, CV_8U);

		LabelDisplayMat(imgDisplay4, ui.label4_2);
		LabelDisplayMat(imgDisplay3, ui.label4_1);

		cv::Mat imgDisplay1 = phaseFG;
		cv::Mat imgDisplay2 = phaseBG;
		ui.progressBar->setValue(100);

		normalize(imgDisplay1, imgDisplay1, 0, 1, CV_MINMAX);
		normalize(imgDisplay2, imgDisplay2, 0, 1, CV_MINMAX);
		ui.progressBar->reset();
		ui.labelStatus->setText("Ready");

		for (int i = 0; i < imgDisplay1.rows; ++i)
		{
			for (int j = 0; j < imgDisplay1.cols; ++j)
			{
				imgDisplay1.at<double>(i, j) *= 255.0;
				imgDisplay2.at<double>(i, j) *= 255.0;
			}
		}

		imgDisplay2.convertTo(imgDisplay2, CV_8U);
		imgDisplay1.convertTo(imgDisplay1, CV_8U);

		LabelDisplayMat(imgDisplay2, ui.label3_2);
		LabelDisplayMat(imgDisplay1, ui.label3_1);

		ui.tabWidget->setCurrentIndex(2);

		isGetP = true;
	}
	else
		emit signalNotOpen();
}

//解包裹
void PMPTrans::on_pushButton2_clicked()
{
	if (isGetP == true)
	{
		ui.labelStatus->setText("unwrap...");
		Sleep(0.5);
		ui.tabWidget->setCurrentIndex(3);
		ui.labelStatus->setText("Ready");
		isUnwrap = true;
	}
		
	else
		emit signalNotGetP();
}

//三维重建
void PMPTrans::on_pushButton3_clicked()
{
	if (isUnwrap == true)
	{
		ui.labelStatus->setText("Reconstructing...");
		ui.progressBar->setValue(10);
		cv::Mat imgDisplay(unwrappedPhase.rows, unwrappedPhase.cols, CV_64FC1);
		unwrappedPhase.convertTo(imgDisplay, CV_64FC1);
		ui.progressBar->setValue(30);
		for (int i = 0; i < imgDisplay.rows; ++i)
		{
			for (int j = 0; j < imgDisplay.cols; ++j)
			{
				imgDisplay.at<double>(i, j) *= 20.0;
			}
			if (i == imgDisplay.rows / 2)
				ui.progressBar->setValue(50);
		}
		Sleep(0.5);
		ui.progressBar->setValue(70);
		QSplitter* spl = new QSplitter(Qt::Horizontal, this);
		Plot* plot = new Plot(spl, imgDisplay);

		ui.progressBar->setValue(80);
		spl->resize(1200, 800);
		spl->move(240, 110);
		ui.progressBar->setValue(90);
		spl->show();
		ui.label_5->setText(codecChild->toUnicode("三维重建结果预览"));
		ui.progressBar->setValue(100);
		Sleep(0.5);
		ui.progressBar->reset();
		ui.labelStatus->setText("Ready");
	}
	else
		emit signalNotUnwrap();

}

void PMPTrans::on_actionFTP_triggered()
{
	connect(ui.actionFTP, SIGNAL(triggered()), this, SLOT(on_actionFTP_triggered));
	//发送信号给主窗口

	//广播信号
	emit signalSwitch();
}
