#include <QGuiApplication>
#include <QSurfaceFormat>
#include "openglwindow.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);

    OpenGLWindow mywindow;
    mywindow.setFormat(format);
    mywindow.resize(640, 480);
    mywindow.show();

    mywindow.setAnimating(true);

    return a.exec();
}
