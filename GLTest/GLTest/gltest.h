#pragma once

#include <QtWidgets/QWidget>
#include <QGLWidget>

#include "ui_gltest.h"

class GLTest : public QGLWidget
{
	Q_OBJECT

public:
	GLTest(QWidget *parent = Q_NULLPTR);

protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);

private:
	Ui::GLTestClass ui;

private:
	void draw();
	int faceAtPosition(const QPoint &pos);
	GLfloat rotationX;
	GLfloat rotationY;
	GLfloat rotationZ;
	QColor faceColors[4];
	QPoint lastPos;

};
