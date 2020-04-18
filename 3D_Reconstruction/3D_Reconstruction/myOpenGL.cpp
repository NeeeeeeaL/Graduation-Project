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

/* 1.1 着色器代码 */
/* *********************************************
*   顶点着色器定义一个输入，它是 4 个成员的矢量 vPosition。
*   主函数声明着色器宣布着色器开始执行。着色器主体非常简单，
*   它复制输入 vPosition 属性到 gl_Position 输出变量中。
*   每个顶点着色器必须输出位置值到 gl_Position 变量中，
*   这个变量传入到管线的下一个阶段中。
*   matrix主要是模型视图矩阵，控制位置和旋转等
* ******************************************** */
/* 顶点着色器 */

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
*   gl_FragColor，gl_FragColor是片段着色器最终的输出值，
*   本例中输出值来自外部传入的颜色数组。
* ******************************************** */

/* 片段着色器 */
static const char *fragmentShaderSourceCore =
					"varying vec2 TexCoord0;\n"
					"uniform sampler2D gSampler;\n"
					"void main() {\n"
					"   gl_FragColor = texture2D(gSampler, TexCoord0.st);\n"
					"}\n";

/* 2.1 正方体顶点的坐标 */
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


/* 2.2 正方体顶点的索引 */
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
* @brief 初始化模型信息vbo【显存】
*/
void MyOpenGL::initVbo()
{
	///< 计算获得数组长度，之后会用到该变量，这样只需要改动这里即可！如果用链表，直接.size()即可求出！
	vVerticesLen = sizeof(vVertices) / sizeof(GLfloat);
	tri_indexLen = sizeof(tri_index) / sizeof(GLuint);
	textureCoordLen = sizeof(texCoords) / sizeof(GLfloat);

	qDebug() << vVerticesLen;
	qDebug() << tri_indexLen;

	///< 初始化顶点buffer并装载数据到显存
	glGenBuffers(1, &verVbo);
	glBindBuffer(GL_ARRAY_BUFFER, verVbo);
	glBufferData(GL_ARRAY_BUFFER, vVerticesLen * sizeof(GLfloat), vVertices, GL_STATIC_DRAW);

	///< 初始化索引buffer并装载数据到显存
	glGenBuffers(1, &v_indexVbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, v_indexVbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, tri_indexLen * sizeof(GLuint), tri_index, GL_STATIC_DRAW);

	///< 初始化纹理坐标buffer并装载到显存
	glGenBuffers(1, &textureVbo);
	glBindBuffer(GL_ARRAY_BUFFER, textureVbo);
	glBufferData(GL_ARRAY_BUFFER, textureCoordLen * sizeof(GLfloat), texCoords, GL_STATIC_DRAW);
}

/**
* @brief 装载纹理，具体纹理知识可以参考网友资料：
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

	///< 转换为OpenGL支持的格式
	tex = QGLWidget::convertToGLFormat(buf);

	///< 开辟一个纹理内存，内存指向texture
	glGenTextures(1, &texture);
	///< 将创建的纹理内存指向的内容绑定到纹理对象GL_TEXTURE_2D上，
	///  经过这句代码后，以后对GL_TEXTURE_2D的操作的任何操作都同时对应与它所绑定的纹理对象
	glBindTexture(GL_TEXTURE_2D, texture);
	///< 开始真正创建纹理数据
	glTexImage2D(GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(),
		0, GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());

	///< 当所显示的纹理比加载进来的纹理小时，采用GL_LINEAR的方法来处理
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	///< 当所显示的纹理比加载进来的纹理大时，采用GL_LINEAR的方法来处理
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void MyOpenGL::initializeGL()
{
	qDebug("+++ initializeGL +++");
	/* 0. 初始化函数，使得函数可以使用 */
	initializeOpenGLFunctions();

	/* 创建项目对象链接着色器 */
	/* 1. 初始化最大的任务是装载顶点和片段着色器 */
	program = new QOpenGLShaderProgram(this);
	/* 一旦应用程序已经创建了顶点、片段着色器对象，
	* 它需要去创建项目对象，项目是最终的链接对象，
	* 每个着色器在被绘制前都应该联系到项目或者项目对象。
	* ***************************************** */
	/* 1.2 加载 */
	if (!program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSourceCore))
	{
		return;
	}
	if (!program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSourceCore))
	{
		return;
	}

	/* 1.3 设置属性位置，将vPosition属性设置为位置0, vertex为位置1
	这里我就让程序自动分配，当然你也可以手动； 我在后面通过代码获取到了！
	*/
	//program->bindAttributeLocation("vertex", 1);
	//program->bindAttributeLocation("vPosition", 0);
	//program->bindAttributeLocation("a_color", 1);
	//program->bindAttributeLocation("matrix", 2);

	/* 1.4 链接项目检查错误 */
	if (!program->link())
	{
		return;
	}

	if (!program->bind()) {
		return;
	}

	///< 获取shaderprogram的id号，然后可以通过id号获取一些属性...
	programid = program->programId();

	///< 从shaderprogram里面获取变量标识，总共用到两种方式，看你喜好！倾向第一种
	matrixLocation = glGetUniformLocation(programid, "matrix");
	vertexLocation = glGetAttribLocation(programid, "vPosition");
	textureLocation = program->attributeLocation("TexCoord");
	samplerLocation = program->uniformLocation("gSampler");

	///< 初始化vbo，对于实时变化的数据，可能需要在paintGL()里面每次调用！
	initVbo();

	///< 装载纹理
	loadTextures();

	///< 允许采用2D纹理技术
	glEnable(GL_TEXTURE_2D);
	///< 设置背景颜色
	glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
	///< 开启深度测试，避免颜色相互透过，具体需要自己深入学习的哦！
	glEnable(GL_DEPTH_TEST);
	///< 设置深度测试类型 - 不设置也会默认
	glDepthFunc(GL_LEQUAL);

	///< 这个地方先于resizeGL运行，所以这里设置无效！我一开始犯了这个错误!!!
	//m_projection.translate(0.0f, 0.0f, -1.0f);
}

void MyOpenGL::resizeGL(int w, int h)
{
	/* 2.1 viewport 设定窗口的原点 origin (x, y)、宽度和高度 */
	glViewport(0, 0, w, h);

	///< 模型矩阵重置
	m_projection.setToIdentity();
	///< 透视投影【做了简单容错】
	qreal aspect = qreal(w) / qreal(h ? h : 1);
	m_projection.perspective(60.0f, aspect, 1.0f, 100.0f);
	///< 增加了模型矩阵，需要做一定偏移量，保证物体刚开始渲染出来时可以被看到！
	m_projection.translate(0.0f, 0.0f, -2.0f);
}

void MyOpenGL::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	///< shader传入模型视图矩阵
	glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, m_projection.data());

	///< shader绑定并启用顶点数组buffer
	glBindBuffer(GL_ARRAY_BUFFER, verVbo);
	glEnableVertexAttribArray(vertexLocation);
	///< 顶点xyz坐标，所以每三个作为一个顶点值
	glVertexAttribPointer(vertexLocation, 3, GL_FLOAT, GL_FALSE, 0, 0);

	///< shader绑定并顶点索引数组buffer - 索引无需启用
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, v_indexVbo);

	///< 绑定纹理
	glUniform1i(samplerLocation, 0);
	glActiveTexture(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindBuffer(GL_ARRAY_BUFFER, textureVbo);
	glEnableVertexAttribArray(textureLocation);
	///< 2是标识两个float为一个纹理坐标，从varying vec2 TexCoord0也可以看出!
	glVertexAttribPointer(textureLocation, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawElements(GL_TRIANGLES, tri_indexLen, GL_UNSIGNED_INT, 0);

	///< 解绑buffer、关闭启用顶点、颜色数组、解绑纹理
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(textureLocation);
	glDisableVertexAttribArray(vertexLocation);
}

/**
* @brief 写了键盘监听事件，可以控制模型旋转，方便预览
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
