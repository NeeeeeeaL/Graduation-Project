#pragma once

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>

class MyOpenGL
{
public:
	MyOpenGL();
	~MyOpenGL();

	void initializeGL();                ///< 初始化
	void resizeGL(int w, int h);        ///< 当窗口发生变化时重新初始化
	void paintGL();                     ///< 绘制

	void initVbo();                     ///< 初始化Vbo
	void loadTextures();                ///< 加载纹理
	void keyPressEvent(QKeyEvent * e);  ///< 键盘事件
private:
	/* [1] 需要定点着色器和片段着色器，不然做不了任何渲染 */
	/*   这里定义了一个着色器[顶点着色器、片段着色器]编译对象 */
	QOpenGLShaderProgram * program;
	///< 可以根据此id，利用glGetUniformLocation等方法获取shader里面的属性
	GLuint programid;

	///< 其实还有视图矩阵、投影矩阵、MVP矩阵，这里简单的用下，不区分特别细！
	///< 分三个这样的矩阵，分别是模型矩阵、视图矩阵、透视矩阵，这样以后灵活性更强:
	///  1. 比如单独控制模型灯光跟随，shader可能需要传入除了mvp矩阵外的模型矩阵*视图矩阵这样一个矩阵
	QMatrix4x4 m_projection;

	///< 矩阵、顶点、颜色在着色器里面的位置
	GLuint matrixLocation, vertexLocation, textureLocation,
		samplerLocation;

	///< 顶点、索引、颜色->buffer的标识
	GLuint verVbo, v_indexVbo, textureVbo;
	GLuint texture;

	int vVerticesLen;   ///< 顶点数组长度
	int tri_indexLen;   ///< 索引数组长度
	int textureCoordLen;///< 纹理坐标数组长度


};

