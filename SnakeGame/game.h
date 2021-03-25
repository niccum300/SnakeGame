#ifndef GAME_H
#define GAME_H

#include "main.h"
#include "map.h"
#include "trianglewindow.h"

const int WINDOW_AMOUNT = 5;
const int SAMPLER_AMOUNT = 16;
const int ERR_WINAMOUNT = 1;

class Game
{
public:
    Game();
    void createWindow(int windowID, int windowWidth, int windowHeight);
    void populateMap(float tileWidth, float tileHeight, int mapWidth, int mapHeight);
    void run();

private:
    TriangleWindow *currentWindows[WINDOW_AMOUNT];
    void initWindows();
    Map gameMap;

};

#endif // GAME_H
