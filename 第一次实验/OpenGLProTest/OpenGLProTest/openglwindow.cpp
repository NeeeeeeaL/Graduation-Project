#include "openglwindow.h"

OpenGLWindow::OpenGLWindow(QWidget *parent)
	: QGLWidget(parent)
{
	QGLFormat format;
	format.setProfile(QGLFormat::CoreProfile);
	format.setVersion(3, 3);
	setFormat(format);
}

OpenGLWindow::~OpenGLWindow()
{
	
}

void OpenGLWindow::initializeGL()
{
	//initializeOpenGLFunctions();//初始化OpenGL函数
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//设置全局变量

	setGeometry(20, 50, 300, 200);//设置窗口初始位置和大小
	glShadeModel(GL_FLAT);//设置阴影平滑模式
	glClearColor(0.1, 1.0, 0.2, 0);//改变窗口的背景颜色，不过我这里貌似设置后并没有什么效果
	glClearDepth(1.0);//设置深度缓存
	glEnable(GL_DEPTH_TEST);//允许深度测试
	glDepthFunc(GL_LEQUAL);//设置深度测试类型
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//进行透视校正
}


void OpenGLWindow::resizeGL(int width, int height)
{
	Q_UNUSED(width);
	Q_UNUSED(height);
}

void OpenGLWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);//清理屏幕
}
