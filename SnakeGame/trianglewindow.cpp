#include "trianglewindow.h"

void TriangleWindow::initialize()
{ 

    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height()* retinaScale);
    gluPerspective(45, (width() / height()) * retinaScale, 0.1, 100.0);
    glTranslatef(0.0, 0.0, -15.0);
}

void TriangleWindow::render()
{

    glClear(GL_COLOR_BUFFER_BIT);
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height()* retinaScale);


    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), verticesPtr, GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof (float), (void*)0);

    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

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
       std::cout << "Up got pressed" << std::endl;
        break;
    case Qt::Key_Down:
       std::cout << "Down got pressed" << std::endl;
        break;
    case Qt::Key_Left:
        std::cout << "Left got pressed" << std::endl;
        break;
    case Qt::Key_Right:
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
