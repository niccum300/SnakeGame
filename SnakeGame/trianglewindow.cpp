#include "trianglewindow.h"

void TriangleWindow::initialize()
{ 
    m_program = new QOpenGLShaderProgram();

    if (!m_program->addShaderFromSourceFile(
        QOpenGLShader::Vertex, ":/shaders/pass_through.vert"))
    {
        qDebug() << "Vertex shader errors :\n" << m_program->log();
    }

    if (!m_program->addShaderFromSourceFile(
        QOpenGLShader::Fragment, ":/shaders/uniform_color.frag"))
    {
        qDebug() << "Fragment shader errors :\n" << m_program->log();
    }

    if (!m_program->link())
        qDebug() << "Shader linker errors :\n" << m_program->log();
}

void TriangleWindow::render()
{

    glClear(GL_COLOR_BUFFER_BIT);
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height()* retinaScale);


    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), verticesPtr, GL_DYNAMIC_DRAW);   // contains all verticies

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof (float), (void*)0);

    glEnableVertexAttribArray(0);

    //glColor3f(0.0f, 1.0f, 0.0f);    // set color to green
    glDrawArrays(GL_QUADS, 0, 8);   // draw verticies as rectangles (from 0 to 4)

    glDisableVertexAttribArray(0);


    ++m_frame;
}

void TriangleWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key_Escape:
       std::cout << "Escape got pressed" << std::endl;
        break;
    case Qt::Key_W:
        glTranslatef(0.0, 0.1, 0.0);
       std::cout << "W got pressed" << std::endl;
        break;
    case Qt::Key_A:
        glTranslatef(-0.1, 0.0, 0.0);
       std::cout << "A got pressed" << std::endl;
        break;
    case Qt::Key_S:
        glTranslatef(0.0f, -0.1, 0.0);
        std::cout << "S got pressed" << std::endl;
        break;
    case Qt::Key_D:
        glTranslatef(0.1, 0.0, 0.0);
        std::cout << "D got pressed" << std::endl;
        break;
    case Qt::Key_Up:
        vertices[1] += 0.1f;
        vertices[4] += 0.1f;
        vertices[7] += 0.1f;
        vertices[10] += 0.1f;
       std::cout << "Up got pressed" << std::endl;

        break;
    case Qt::Key_Down:
        vertices[1] -= 0.1f;
        vertices[4] -= 0.1f;
        vertices[7] -= 0.1f;
        vertices[10] -= 0.1f;

       std::cout << "Down got pressed" << std::endl;
        break;
    case Qt::Key_Left:
        vertices[0] -= 0.1f;
        vertices[3] -= 0.1f;
        vertices[6] -= 0.1f;
        vertices[9] -= 0.1f;

        std::cout << "Left got pressed" << std::endl;
        break;
    case Qt::Key_Right:
        vertices[0] += 0.1f;
        vertices[3] += 0.1f;
        vertices[6] += 0.1f;
        vertices[9] += 0.1f;

        std::cout << "Right got pressed" << std::endl;
        break;
    case Qt::Key_1:
        glTranslatef(0.0, 0.0, -0.5);
        std::cout << "One got pressed" << std::endl;
        break;
    case Qt::Key_2:
        glTranslatef(0.0, 0.0, 0.5);
        std::cout << "Two got pressed" << std::endl;
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
