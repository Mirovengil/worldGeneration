#include "WorldsMap.h"
#include <stdlib.h>

WorldsMap::WorldsMap()
{    
}

WorldsMap::~WorldsMap()
{

}

void WorldsMap::initHeightMatrix(const WorldsSettings &settings)
{
    srand(settings.randomSeed);
    
    uint8_t threshold = 128;
    uint8_t rnd;

    heightsMatrix.resize(settings.matrixHeight, settings.matrixWidth);
    heightsStayingAlive.resize(settings.matrixHeight, settings.matrixWidth);

    for (int i = 0; i < heightsMatrix.height(); ++i)
    {
        for (int j = 0; j < heightsMatrix.width(); ++j)
        {
            rnd = rand() % 256;
            if (rnd > threshold)
                heightsMatrix.at(i, j) = 255;
            else
                heightsMatrix.at(i, j) = 0;
        }
    }
}

Matrix<uint8_t>* WorldsMap::getHeightsMatrix()
{
    return &heightsMatrix;
}

void WorldsMap::processHeightMatrix()
{
    // TODO : добавь проверку, что матрица инициализирована

    heightsStayingAlive.fillDataWithZeros();

    uint8_t neighbours;
    uint8_t self;
    for (int v = 0; v < heightsMatrix.height(); ++v)
        for (int h = 0; h < heightsMatrix.width(); ++h)
        {
            self = (heightsMatrix.at(v, h) == 255);
            neighbours = cntNeighbours(v, h);
            
            if ((neighbours == 3 || neighbours == 4 || neighbours == 6 || neighbours == 7 || neighbours == 8)
                && (self))
            {
                heightsStayingAlive.at(v, h) = 255;
            }

            if ((neighbours == 3 || neighbours == 6 || neighbours == 7 || neighbours == 8)
                && (!self))
            {
                heightsStayingAlive.at(v, h) = 255;
            }

            // if (neighbours > 4)
            // {
            //     heightsStayingAlive.at(v, h) = 255;
            // }
            // else
            // if (neighbours < 4)
            //     heightsStayingAlive.at(v, h) = 0;
            // else
            //     heightsStayingAlive.at(v, h) = heightsMatrix.at(v, h);
        }

    heightsStayingAlive.copyTo(&heightsMatrix);

}

uint8_t WorldsMap::cntNeighbours(uint32_t v, uint32_t h)
{
    uint8_t cnt = 0;

    for (int i = -1; i <= 1; ++i)
    for (int j = -1; j <= 1; ++j)
    {
        if (i == 0 && j == 0) continue;
        if (v + i < 0 || h + j < 0) continue;
        if (v + i >= heightsMatrix.height() || h + j >= heightsMatrix.width()) continue;
        
        cnt += (heightsMatrix.at(v + i, h + j) == 255);
    }

    return cnt;
}
