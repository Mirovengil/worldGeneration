#ifndef WORLDS_MAP_H
#define WORLDS_MAP_H

#include <stdint.h>

#include "WorldsSettings.h"
#include "Matrix.h"
class WorldsMap
{
private:
    Matrix<uint8_t> heightsMatrix;

public:
    WorldsMap();
    ~WorldsMap();

    void generate(const WorldsSettings &settings);
};

#endif