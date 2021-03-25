#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <GL/glu.h>

#include <QGuiApplication>
#include <QKeyEvent>
#include <QPainter>
#include <QScreen>
#include <QSurfaceFormat>
#include <QWindow>

#include <QOpenGLFunctions>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>

#endif // MAIN_H


#ifndef TILE_H
#define TILE_H

struct Tile {
    float x = 0;
    float y = 0;
    float z = 0;
    float width = 0;
    float height = 0;
    float color[3] = {0, 1.0f, 0};
};

#endif //TILE_H
