#ifndef WORLDS_SETTINGS
#define WORLDS_SETTINGS

// Рекомендуется создавать с модификтором const!
struct WorldsSettings
{
    // ширина и высота матрицы, в виде которой представляется мир
    int matrixHeight;
    int matrixWidth;

    // сид для ГСЧ
    int randomSeed;

};

#endif 