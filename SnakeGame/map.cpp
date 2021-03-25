#include "map.h"

Map::Map()
{

}

void Map::createTiles()
{
    int index = 0;
    for(int i = 0; i < sizeMap[0]; i++)
    {
        for(int j = 0; j < sizeMap[1]; j++)
        {
            map[index].x = i * sizeTile[0];
            map[index].y = j * sizeTile[1];
            map[index].width = sizeTile[0];
            map[index].height = sizeTile[1];
            index++;
        }
    }
    vertices = new float[(sizeMap[0] * sizeMap[1] * 8)];
}

void Map::createVertices()
{
    for(int i = 0; i < sizeMap[0] * sizeMap[1] * 8; i+=8)
    {
        vertices[i] = map[i/8].x + map[i/8].width;
        vertices[i+1] = map[i/8].y;

        vertices[i+2] = map[i/8].x;
        vertices[i+3] = map[i/8].y;

        vertices[i+4] = map[i/8].x;
        vertices[i+5] = map[i/8].y + map[i/8].height;

        vertices[i+6] = map[i/8].x + map[i/8].width;
        vertices[i+7] = map[i/8].y + map[i/8].height;
    }
}

int *Map::getMapSize()
{
    return sizeMap;
}

float *Map::getTileSize()
{
    return sizeTile;
}

float *Map::getVertices()
{
    return vertices;
}

uint Map::getVerticeSize()
{
    return (sizeMap[0] * sizeMap[1] * 8);
}

void Map::setMapSize(int mapWidth, int mapHeight)
{
    sizeMap[0] = mapWidth;
    sizeMap[1] = mapHeight;

    map = new Tile[(sizeMap[0] * sizeMap[1])];
}

void Map::setTileSize(float tileWidth, float tileHeight)
{
    sizeTile[0] = tileWidth;
    sizeTile[1] = tileHeight;
}
