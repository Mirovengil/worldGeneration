#ifndef WORLDS_MAP_H
#define WORLDS_MAP_H

#include <stdint.h>

#include "WorldsSettings.h"
#include "Matrix.h"

class WorldsMap
{
private:
    Matrix<uint8_t> heightsMatrix;

    void showHeightMatrix();
public:
    WorldsMap();
    ~WorldsMap();

    void init(const WorldsSettings &settings);

    Matrix<uint8_t>* getHeightsMatrix();
};

#endif