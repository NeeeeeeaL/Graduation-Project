#include "myOpenGL.h"
#include <QKeyEvent>
#include <QGLWidget>
#include <QOpenGLFunctions_3_2_Core>


MyOpenGL::MyOpenGL()
{
}


MyOpenGL::~MyOpenGL()
{
	glDeleteBuffers(1, &verVbo);
	glDeleteBuffers(1, &v_indexVbo);
	glDeleteProgram(programid);
	glDeleteTextures(1, &texture);
}

/* 1.1 ��ɫ������ */
/* *********************************************
*   ������ɫ������һ�����룬���� 4 ����Ա��ʸ�� vPosition��
*   ������������ɫ��������ɫ����ʼִ�С���ɫ������ǳ��򵥣�
*   ���������� vPosition ���Ե� gl_Position ��������С�
*   ÿ��������ɫ���������λ��ֵ�� gl_Position �����У�
*   ����������뵽���ߵ���һ���׶��С�
*   matrix��Ҫ��ģ����ͼ���󣬿���λ�ú���ת��
* ******************************************** */
/* ������ɫ�� */

static const char *vertexShaderSourceCore =
					"attribute vec4 vPosition;\n"
					"uniform highp mat4 matrix;\n"
					"attribute vec2 TexCoord;\n"
					"varying vec2 TexCoord0;\n"
					"void main() {\n"
					"   TexCoord0 = TexCoord;\n"
					"   gl_Position = matrix * vPosition;\n"
					"}\n";

/* *********************************************
*   gl_FragColor��gl_FragColor��Ƭ����ɫ�����յ����ֵ��
*   ���������ֵ�����ⲿ�������ɫ���顣
* ******************************************** */

/* Ƭ����ɫ�� */
static const char *fragmentShaderSourceCore =
					"varying vec2 TexCoord0;\n"
					"uniform sampler2D gSampler;\n"
					"void main() {\n"
					"   gl_FragColor = texture2D(gSampler, TexCoord0.st);\n"
					"}\n";

/* 2.1 �����嶥������� */
GLfloat vVertices[] = { -0.5f, -0.5f, 0.5f,
						0.5f, -0.5f, 0.5f,
						-0.5f,  0.5f, 0.5f,
						0.5f,  0.5f, 0.5f,

						-0.5f, -0.5f,  -0.5f,
						0.5f, -0.5f,  -0.5f,
						-0.5f,  0.5f,  -0.5f,
						0.5f,  0.5f,  -0.5f,

						-0.5f, -0.5f,  -0.5f,
						-0.5f, -0.5f,  0.5f,
						-0.5f,  0.5f,  -0.5f,
						-0.5f,  0.5f,  0.5f,

						0.5f, -0.5f,  -0.5f,
						0.5f, -0.5f,  0.5f,
						0.5f,  0.5f,  -0.5f,
						0.5f,  0.5f,  0.5f,

						-0.5f, 0.5f,  -0.5f,
						-0.5f, 0.5f,  0.5f,
						0.5f,  0.5f,  -0.5f,
						0.5f,  0.5f,  0.5f,

						-0.5f, -0.5f,  -0.5f,
						-0.5f, -0.5f,  0.5f,
						0.5f,  -0.5f,  -0.5f,
						0.5f,  -0.5f,  0.5f };


/* 2.2 �����嶥������� */
GLuint tri_index[] = { 0, 3, 2,
						0, 1, 3,
						4, 7, 6,
						4, 5, 7,
						8, 11, 10,
						8, 9, 11,
						12, 15, 14,
						12, 13, 15,
						16, 19, 18,
						16, 17, 19,
						20, 23, 22,
						20, 21, 23 };


float texCoords[] =
{
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,

	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,

	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,

	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,

	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,

	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f
};


/**
* @brief ��ʼ��ģ����Ϣvbo���Դ桿
*/
void MyOpenGL::initVbo()
{
	///< ���������鳤�ȣ�֮����õ��ñ���������ֻ��Ҫ�Ķ����Ｔ�ɣ����������ֱ��.size()���������
	vVerticesLen = sizeof(vVertices) / sizeof(GLfloat);
	tri_indexLen = sizeof(tri_index) / sizeof(GLuint);
	textureCoordLen = sizeof(texCoords) / sizeof(GLfloat);

	qDebug() << vVerticesLen;
	qDebug() << tri_indexLen;

	///< ��ʼ������buffer��װ�����ݵ��Դ�
	glGenBuffers(1, &verVbo);
	glBindBuffer(GL_ARRAY_BUFFER, verVbo);
	glBufferData(GL_ARRAY_BUFFER, vVerticesLen * sizeof(GLfloat), vVertices, GL_STATIC_DRAW);

	///< ��ʼ������buffer��װ�����ݵ��Դ�
	glGenBuffers(1, &v_indexVbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, v_indexVbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, tri_indexLen * sizeof(GLuint), tri_index, GL_STATIC_DRAW);

	///< ��ʼ����������buffer��װ�ص��Դ�
	glGenBuffers(1, &textureVbo);
	glBindBuffer(GL_ARRAY_BUFFER, textureVbo);
	glBufferData(GL_ARRAY_BUFFER, textureCoordLen * sizeof(GLfloat), texCoords, GL_STATIC_DRAW);
}

/**
* @brief װ��������������֪ʶ���Բο��������ϣ�
* http://www.cnblogs.com/tornadomeet/archive/2012/08/24/2654719.html
*/
void MyOpenGL::loadTextures()
{
	QImage tex, buf;
	if (!buf.load("../2012082420060914.jpg"))
	{
		qWarning("annot open the image...");
		QImage dummy(128, 128, QImage::Format_RGB32);
		dummy.fill(Qt::green);
		buf = dummy;
	}

	///< ת��ΪOpenGL֧�ֵĸ�ʽ
	tex = QGLWidget::convertToGLFormat(buf);

	///< ����һ�������ڴ棬�ڴ�ָ��texture
	glGenTextures(1, &texture);
	///< �������������ڴ�ָ������ݰ󶨵��������GL_TEXTURE_2D�ϣ�
	///  ������������Ժ��GL_TEXTURE_2D�Ĳ������κβ�����ͬʱ��Ӧ�������󶨵��������
	glBindTexture(GL_TEXTURE_2D, texture);
	///< ��ʼ����������������
	glTexImage2D(GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(),
		0, GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());

	///< ������ʾ������ȼ��ؽ���������Сʱ������GL_LINEAR�ķ���������
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	///< ������ʾ������ȼ��ؽ����������ʱ������GL_LINEAR�ķ���������
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void MyOpenGL::initializeGL()
{
	qDebug("+++ initializeGL +++");
	/* 0. ��ʼ��������ʹ�ú�������ʹ�� */
	initializeOpenGLFunctions();

	/* ������Ŀ����������ɫ�� */
	/* 1. ��ʼ������������װ�ض����Ƭ����ɫ�� */
	program = new QOpenGLShaderProgram(this);
	/* һ��Ӧ�ó����Ѿ������˶��㡢Ƭ����ɫ������
	* ����Ҫȥ������Ŀ������Ŀ�����յ����Ӷ���
	* ÿ����ɫ���ڱ�����ǰ��Ӧ����ϵ����Ŀ������Ŀ����
	* ***************************************** */
	/* 1.2 ���� */
	if (!program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSourceCore))
	{
		return;
	}
	if (!program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSourceCore))
	{
		return;
	}

	/* 1.3 ��������λ�ã���vPosition��������Ϊλ��0, vertexΪλ��1
	�����Ҿ��ó����Զ����䣬��Ȼ��Ҳ�����ֶ��� ���ں���ͨ�������ȡ���ˣ�
	*/
	//program->bindAttributeLocation("vertex", 1);
	//program->bindAttributeLocation("vPosition", 0);
	//program->bindAttributeLocation("a_color", 1);
	//program->bindAttributeLocation("matrix", 2);

	/* 1.4 ������Ŀ������ */
	if (!program->link())
	{
		return;
	}

	if (!program->bind()) {
		return;
	}

	///< ��ȡshaderprogram��id�ţ�Ȼ�����ͨ��id�Ż�ȡһЩ����...
	programid = program->programId();

	///< ��shaderprogram�����ȡ������ʶ���ܹ��õ����ַ�ʽ������ϲ�ã������һ��
	matrixLocation = glGetUniformLocation(programid, "matrix");
	vertexLocation = glGetAttribLocation(programid, "vPosition");
	textureLocation = program->attributeLocation("TexCoord");
	samplerLocation = program->uniformLocation("gSampler");

	///< ��ʼ��vbo������ʵʱ�仯�����ݣ�������Ҫ��paintGL()����ÿ�ε��ã�
	initVbo();

	///< װ������
	loadTextures();

	///< �������2D������
	glEnable(GL_TEXTURE_2D);
	///< ���ñ�����ɫ
	glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
	///< ������Ȳ��ԣ�������ɫ�໥͸����������Ҫ�Լ�����ѧϰ��Ŷ��
	glEnable(GL_DEPTH_TEST);
	///< ������Ȳ������� - ������Ҳ��Ĭ��
	glDepthFunc(GL_LEQUAL);

	///< ����ط�����resizeGL���У���������������Ч����һ��ʼ�����������!!!
	//m_projection.translate(0.0f, 0.0f, -1.0f);
}

void MyOpenGL::resizeGL(int w, int h)
{
	/* 2.1 viewport �趨���ڵ�ԭ�� origin (x, y)����Ⱥ͸߶� */
	glViewport(0, 0, w, h);

	///< ģ�;�������
	m_projection.setToIdentity();
	///< ͸��ͶӰ�����˼��ݴ�
	qreal aspect = qreal(w) / qreal(h ? h : 1);
	m_projection.perspective(60.0f, aspect, 1.0f, 100.0f);
	///< ������ģ�;�����Ҫ��һ��ƫ��������֤����տ�ʼ��Ⱦ����ʱ���Ա�������
	m_projection.translate(0.0f, 0.0f, -2.0f);
}

void MyOpenGL::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	///< shader����ģ����ͼ����
	glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, m_projection.data());

	///< shader�󶨲����ö�������buffer
	glBindBuffer(GL_ARRAY_BUFFER, verVbo);
	glEnableVertexAttribArray(vertexLocation);
	///< ����xyz���꣬����ÿ������Ϊһ������ֵ
	glVertexAttribPointer(vertexLocation, 3, GL_FLOAT, GL_FALSE, 0, 0);

	///< shader�󶨲�������������buffer - ������������
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, v_indexVbo);

	///< ������
	glUniform1i(samplerLocation, 0);
	glActiveTexture(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindBuffer(GL_ARRAY_BUFFER, textureVbo);
	glEnableVertexAttribArray(textureLocation);
	///< 2�Ǳ�ʶ����floatΪһ���������꣬��varying vec2 TexCoord0Ҳ���Կ���!
	glVertexAttribPointer(textureLocation, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawElements(GL_TRIANGLES, tri_indexLen, GL_UNSIGNED_INT, 0);

	///< ���buffer���ر����ö��㡢��ɫ���顢�������
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(textureLocation);
	glDisableVertexAttribArray(vertexLocation);
}

/**
* @brief д�˼��̼����¼������Կ���ģ����ת������Ԥ��
* @param k
*/
void MyOpenGL::keyPressEvent(QKeyEvent * k)
{
	qDebug("+++ keyPressEvent +++");
	if (k->key() == Qt::Key_A)
	{
		m_projection.rotate(4, 0, 1, 0);
	}
	else if (k->key() == Qt::Key_D)
	{
		m_projection.rotate(-4, 0, 1, 0);
	}
	else if (k->key() == Qt::Key_W)
	{
		m_projection.rotate(4, 1, 0, 0);
	}
	else if (k->key() == Qt::Key_S)
	{
		m_projection.rotate(-4, 1, 0, 0);
	}
	update();
}
