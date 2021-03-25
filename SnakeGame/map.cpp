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
    vertices = new float[(sizeMap[0] * sizeMap[1] * VERTEX_COUNT)];
}

void Map::createVertices()
{
    for(int i = 0; i < sizeMap[0] * sizeMap[1] * VERTEX_COUNT; i+=VERTEX_COUNT)
    {
        if(VERTEX_COUNT == 8)
        {
            vertices[i] = map[i/VERTEX_COUNT].x + map[i/VERTEX_COUNT].width;
            vertices[i+1] = map[i/VERTEX_COUNT].y;

            vertices[i+2] = map[i/VERTEX_COUNT].x;
            vertices[i+3] = map[i/VERTEX_COUNT].y;

            vertices[i+4] = map[i/VERTEX_COUNT].x;
            vertices[i+5] = map[i/VERTEX_COUNT].y + map[i/VERTEX_COUNT].height;

            vertices[i+6] = map[i/VERTEX_COUNT].x + map[i/VERTEX_COUNT].width;
            vertices[i+7] = map[i/VERTEX_COUNT].y + map[i/VERTEX_COUNT].height;
        }
        else if(VERTEX_COUNT == 12)
        {
            vertices[i] = map[i/VERTEX_COUNT].x + map[i/VERTEX_COUNT].width;
            vertices[i+1] = map[i/VERTEX_COUNT].y;
            vertices[i+2] = map[i/VERTEX_COUNT].z;

            vertices[i+3] = map[i/VERTEX_COUNT].x;
            vertices[i+4] = map[i/VERTEX_COUNT].y;
            vertices[i+5] = map[i/VERTEX_COUNT].z;

            vertices[i+6] = map[i/VERTEX_COUNT].x;
            vertices[i+7] = map[i/VERTEX_COUNT].y + map[i/VERTEX_COUNT].height;
            vertices[i+8] = map[i/VERTEX_COUNT].z;

            vertices[i+9] = map[i/VERTEX_COUNT].x + map[i/VERTEX_COUNT].width;
            vertices[i+10] = map[i/VERTEX_COUNT].y + map[i/VERTEX_COUNT].height;
            vertices[i+11] = map[i/VERTEX_COUNT].z;
        }
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
    return (sizeMap[0] * sizeMap[1] * VERTEX_COUNT);
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
