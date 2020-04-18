#include "play.h"
#include <QImage>
#include <QDebug>

Play::Play(QWindow  *parent)
	: QOpenGLWindow(parent)
{
	//ui.setupUi(this);

	rTri = 0.0;
	rQuad = 0.0;
	xRot = yRot = zRot = 0.0;
}


void Play::loadGLTextures()
{
	QImage tex, buf;
	if (!buf.load("./msbg_blue.png"))
	{
		qWarning("Could not read image file, using single-color instead.");
		QImage dummy(128, 128, QImage::Format_RGB32);
		dummy.fill(Qt::green);
		buf = dummy;
	}
	tex = QGLWidget::convertToGLFormat(buf);

	glGenTextures(1, &texture[0]);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(), 0,
		GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}
//初始化opengl窗口部件
void Play::initializeGL()
{
	initializeOpenGLFunctions();
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_SMOOTH);

	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//绘制opengl窗口
void Play::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(-1.5f, 0.0f, -6.0f);
	glRotatef(rTri, 0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.0, -1.0, -1.0);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.0, -1.0, -1.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-1.0, -1.0, -1.0);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glEnd();

	glTranslatef(3.0f, 0.0f, -7.0f);
	glRotatef(rQuad, 0.0, 0.0, 1.0);
	glRotatef(rTri, 0.0, 1.0, 0.0);
	glRotatef(rQuad, 0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);

	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(1.0, -1.0, -1.0);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);

	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(1.0, 1.0, -1.0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);

	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glEnd();
	rTri += 0.2;
	rQuad -= 0.15;
}
//处理窗口大小
void Play::resizeGL(int width, int height)
{
	glViewport(0, 0, (GLint)width, (GLint)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);         //选择模型观察矩阵
	glLoadIdentity();                   //重置模型观察矩阵
}