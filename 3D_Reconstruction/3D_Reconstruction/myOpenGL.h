#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>

class MyOpenGL
{
public:
	MyOpenGL();
	~MyOpenGL();

	void initializeGL();                ///< ��ʼ��
	void resizeGL(int w, int h);        ///< �����ڷ����仯ʱ���³�ʼ��
	void paintGL();                     ///< ����

	void initVbo();                     ///< ��ʼ��Vbo
	void loadTextures();                ///< ��������
	void keyPressEvent(QKeyEvent * e);  ///< �����¼�
private:
	/* [1] ��Ҫ������ɫ����Ƭ����ɫ������Ȼ�������κ���Ⱦ */
	/*   ���ﶨ����һ����ɫ��[������ɫ����Ƭ����ɫ��]������� */
	QOpenGLShaderProgram * program;
	///< ���Ը��ݴ�id������glGetUniformLocation�ȷ�����ȡshader���������
	GLuint programid;

	///< ��ʵ������ͼ����ͶӰ����MVP��������򵥵����£��������ر�ϸ��
	///< �����������ľ��󣬷ֱ���ģ�;�����ͼ����͸�Ӿ��������Ժ�����Ը�ǿ:
	///  1. ���絥������ģ�͵ƹ���棬shader������Ҫ�������mvp�������ģ�;���*��ͼ��������һ������
	QMatrix4x4 m_projection;

	///< ���󡢶��㡢��ɫ����ɫ�������λ��
	GLuint matrixLocation, vertexLocation, textureLocation,
		samplerLocation;

	///< ���㡢��������ɫ->buffer�ı�ʶ
	GLuint verVbo, v_indexVbo, textureVbo;
	GLuint texture;

	int vVerticesLen;   ///< �������鳤��
	int tri_indexLen;   ///< �������鳤��
	int textureCoordLen;///< �����������鳤��


};

