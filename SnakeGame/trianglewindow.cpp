#include "trianglewindow.h"

void TriangleWindow::initialize()
{
    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    m_program->link();
    m_posAttr = m_program->attributeLocation("posAttr");
    Q_ASSERT(m_posAttr != -1);
    m_colAttr = m_program->attributeLocation("colAttr");
    Q_ASSERT(m_colAttr != -1);
    m_matrixUniform = m_program->uniformLocation("matrix");
    Q_ASSERT(m_matrixUniform != -1);
    matrix.perspective(45.0f, 4.0f / 3.0f, 0.1f, 50.0f);
    matrix.translate(0, 0, -10);
}

void TriangleWindow::render()
{
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    glClear(GL_COLOR_BUFFER_BIT);

    m_program->bind();

//    QMatrix4x4 matrix;
//    matrix.perspective(60.0f, 4.0f / 3.0f, 0.1f, 100.0f);
//    matrix.translate(0, 0, -2);
    //matrix.rotate(100.0f * m_frame / screen()->refreshRate(), 0, 1, 0);

    m_program->setUniformValue(m_matrixUniform, matrix);

    static const GLfloat vertices[] = {
         0.0f,  0.707f,
        -0.5f, -0.5f,
         0.5f, -0.5f
    };

    static const GLfloat colors[] = {
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    };

    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colAttr);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(m_colAttr);
    glDisableVertexAttribArray(m_posAttr);

    m_program->release();

    ++m_frame;
}

void TriangleWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key_Escape:
       std::cout << "Escape got pressed" << std::endl;
        break;
    case Qt::Key_W:
        matrix.translate(0, 0, 0.5);
       std::cout << "W got pressed" << std::endl;
        break;
    case Qt::Key_A:
       std::cout << "A got pressed" << std::endl;
        break;
    case Qt::Key_S:
        matrix.translate(0, 0, -0.5);
        std::cout << "S got pressed" << std::endl;
        break;
    case Qt::Key_D:
        std::cout << "D got pressed" << std::endl;
        break;
    case Qt::Key_Up:
        matrix.translate(0, 0.1, 0);
       std::cout << "Up got pressed" << std::endl;
        break;
    case Qt::Key_Down:
        matrix.translate(0, -0.1, 0);
       std::cout << "Down got pressed" << std::endl;
        break;
    case Qt::Key_Left:
        matrix.translate(-0.1, 0, 0);
        std::cout << "Left got pressed" << std::endl;
        break;
    case Qt::Key_Right:
        matrix.translate(0.1, 0, 0);
        std::cout << "Right got pressed" << std::endl;
        break;

    }
}

void TriangleWindow::keyReleaseEvent(QKeyEvent *event) {
    switch(event->key()) {
    case Qt::Key_Escape:
       std::cout << "Escape released" << std::endl;
        break;
    case Qt::Key_W:
       std::cout << "W released" << std::endl;
        break;
    case Qt::Key_A:
       std::cout << "A released" << std::endl;
        break;
    case Qt::Key_S:
        std::cout << "S released" << std::endl;
        break;
    case Qt::Key_D:
        std::cout << "D released" << std::endl;
        break;
    case Qt::Key_Up:
       std::cout << "Up released" << std::endl;
        break;
    case Qt::Key_Down:
       std::cout << "Down released" << std::endl;
        break;
    case Qt::Key_Left:
        std::cout << "Left released" << std::endl;
        break;
    case Qt::Key_Right:
        std::cout << "Right released" << std::endl;
        break;

    }
}
