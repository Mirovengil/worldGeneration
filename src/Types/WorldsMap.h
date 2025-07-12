#ifndef WORLDS_MAP_H
#define WORLDS_MAP_H

#include <stdint.h>

#include "WorldsSettings.h"
#include "Matrix.h"

class WorldsMap
{
private:
    Matrix<uint8_t> heightsMatrix;
    Matrix<uint8_t> temporalMatrix;
public:
    WorldsMap();
    ~WorldsMap();

    uint32_t height();
    uint32_t width();

    void initWorld(const WorldsSettings &settings);
    void processHeightMatrix();
    uint8_t cntNeighbours(uint32_t v, uint32_t h);

    void doMedianFiltrationForMatrixOfHeights(uint8_t radius);
    uint8_t resultOfMedianFilterInPoint(uint32_t v, uint32_t h, uint8_t radius);

    Matrix<uint8_t>* getHeightsMatrix();
};

#endif