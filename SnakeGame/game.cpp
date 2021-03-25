#include "game.h"

Game::Game()
{
    for(int i = 0; i < WINDOW_AMOUNT; i++)
    {
        currentWindows[i] = NULL;
    }
}

void Game::run()
{
    initWindows();
}

void Game::createWindow(int windowID, int windowWidth, int windowHeight)
{
    try {
        if(windowID >= 0 && windowID < WINDOW_AMOUNT)
        {
            QSurfaceFormat format;
            format.setSamples(SAMPLER_AMOUNT);

            currentWindows[windowID] =  new TriangleWindow();
            currentWindows[windowID]->setFormat(format);
            currentWindows[windowID]->resize(windowWidth, windowHeight);
        }
        else{
            throw(ERR_WINAMOUNT);
        }
    } catch (int e) {
        if(e == ERR_WINAMOUNT){
            std::cout<<"Game: createWindow(): windowID must be between 0 and " << WINDOW_AMOUNT<<std::endl;
        }
    }

}

void Game::initWindows()
{
    for(int i = 0; i < WINDOW_AMOUNT; i++)
    {
        if (currentWindows[i] != nullptr)
        {
            std::cout<<"Running Window "<<i<<"..."<<std::endl;
            currentWindows[i]->show();
            currentWindows[i]->setAnimating(true);
        }
    }
}

void Game::populateMap(float tileWidth, float tileHeight, int mapWidth, int mapHeight)
{
    gameMap.setMapSize(mapWidth, mapHeight);
    gameMap.setTileSize(tileWidth, tileHeight);
    gameMap.createTiles();
    gameMap.createVertices();
}

void Game::bindMapWindow(int windowID)
{
    currentWindows[windowID]->setVerticies(gameMap.getVertices(), gameMap.getVerticeSize());
}
