#pragma once

#include <QGLWidget>
#include <qopenglfunctions_3_3_core.h>

class OpenGLWindow : public QGLWidget
{
	Q_OBJECT

public:
	OpenGLWindow(QWidget *parent);
	~OpenGLWindow();

	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
};
