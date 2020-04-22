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
	//initializeOpenGLFunctions();//��ʼ��OpenGL����
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//����ȫ�ֱ���

	setGeometry(20, 50, 300, 200);//���ô��ڳ�ʼλ�úʹ�С
	glShadeModel(GL_FLAT);//������Ӱƽ��ģʽ
	glClearColor(0.1, 1.0, 0.2, 0);//�ı䴰�ڵı�����ɫ������������ò�����ú�û��ʲôЧ��
	glClearDepth(1.0);//������Ȼ���
	glEnable(GL_DEPTH_TEST);//������Ȳ���
	glDepthFunc(GL_LEQUAL);//������Ȳ�������
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//����͸��У��
}


void OpenGLWindow::resizeGL(int width, int height)
{
	Q_UNUSED(width);
	Q_UNUSED(height);
}

void OpenGLWindow::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);//������Ļ
}
