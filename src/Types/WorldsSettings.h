#ifndef WORLDS_SETTINGS
#define WORLDS_SETTINGS

#include <stdint.h>

// Рекомендуется создавать с модификтором const!
struct WorldsSettings
{
    // ширина и высота матрицы, в виде которой представляется мир
    uint32_t matrixHeight;
    uint32_t matrixWidth;

    // сид для ГСЧ
    uint32_t randomSeed;

    // 0 ~ генерируются только клетки воды
    // 255 ~ генерируются только клетки суши
    uint8_t percentOfSand;

};

#endif 