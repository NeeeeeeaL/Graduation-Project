#pragma once

#include <QtWidgets/QWidget>
#include "ui_play.h"

#include <QOpenGLWidget>
#include <QOpenGLWindow>
#include <QGLWidget>
#include <QGLFunctions>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
#include <GL/glu.h>

class Play : QOpenGLWindow, protected QOpenGLFunctions
{
	Q_OBJECT

public:
	Play(QWindow *parent = Q_NULLPTR);

private:
	Ui::PlayClass ui;

protected:
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int width, int height) override;
	void loadGLTextures();
protected:
	GLfloat rTri;
	GLfloat rQuad;
	GLfloat xRot, yRot, zRot;
	GLuint texture[1];
private:

};
