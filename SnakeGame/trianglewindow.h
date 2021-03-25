#ifndef TRIANGLEWINDOW_H
#define TRIANGLEWINDOW_H

#include "main.h"
#include "openglwindow.h"

class TriangleWindow : public OpenGLWindow
{
public:
    using OpenGLWindow::OpenGLWindow;

    void initialize() override;
    void render() override;
    void setVerticies(float *vertices, uint arraySize);

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;

    GLfloat *verticesPtr;
    uint vertexSize = 0;

    QOpenGLShaderProgram *m_program = nullptr;
    int m_frame = 0;

};

#endif // TRIANGLEWINDOW_H
