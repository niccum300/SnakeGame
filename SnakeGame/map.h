#ifndef MAP_H
#define MAP_H

#include "main.h"

const int VERTEX_COUNT = 12;

class Map
{
public:
    Map();

    void createTiles();
    void createVertices();

    void setMapSize(int mapWidth, int mapHeight);
    void setTileSize(float tileWidth, float tileHeight);

    int *getMapSize();
    float *getTileSize();
    float *getVertices();
    uint getVerticeSize();

private:
    int sizeMap[2];
    float sizeTile[2];
    float *vertices;
    Tile *map;
};

#endif // MAP_H
