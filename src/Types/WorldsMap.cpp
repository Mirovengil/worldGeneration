#include "WorldsMap.h"

WorldsMap::WorldsMap()
{    
}

WorldsMap::~WorldsMap()
{

}

void WorldsMap::init(const WorldsSettings &settings)
{
    heightsMatrix.resize(settings.matrixHeight, settings.matrixWidth);
    
    // пока не оттестировал отрисовку на openGL -- буду красить матрицу высот 
    // в попеременные полоски: min, max, min, max
    bool isLight = true;
    for (int i = 0; i < heightsMatrix.height(); ++i)
    {
        if (i % 50 == 0)
            isLight = !isLight;
        
        for (int j = 0; j < heightsMatrix.width(); ++j)
        {
            if (isLight)
                heightsMatrix.at(i, j) = 255;
            else
                heightsMatrix.at(i, j) = 0;
        }
    }
}

void WorldsMap::showHeightMatrix()
{

}

Matrix<uint8_t>* WorldsMap::getHeightsMatrix()
{
    return &heightsMatrix;
}

