#include <QGuiApplication>
#include <QSurfaceFormat>
#include "trianglewindow.h"

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);

    TriangleWindow mywindow;
    mywindow.setFormat(format);
    mywindow.resize(640, 480);
    mywindow.show();

    mywindow.setAnimating(true);

    return a.exec();
}
