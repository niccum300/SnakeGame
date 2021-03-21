#ifndef TRIANGLEWINDOW_H
#define TRIANGLEWINDOW_H

#include "openglwindow.h"
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include <iostream>
#include <GL/glu.h>

class TriangleWindow : public OpenGLWindow
{
public:
    using OpenGLWindow::OpenGLWindow;

    void initialize() override;
    void render() override;

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;

    GLfloat vertices[9] = {
        16.5f,  16.5f, 0.0f,  // top right
        16.5f, -16.5f, 0.0f,  // bottom right
       -16.5f,  16.5f, 0.0f  // top left
    };

    GLfloat *verticesPtr = vertices;

    QOpenGLShaderProgram *m_program = nullptr;
    int m_frame = 0;

};

#endif // TRIANGLEWINDOW_H
