#include <QApplication>

// отрисовка
#include "MainWindow.h"

// типы данных
#include "WorldsMap.h"

 // алгоритмы

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
 
    WorldsSettings worldsSettings;
    worldsSettings.matrixHeight = 500;
    worldsSettings.matrixWidth = 500;
    worldsSettings.randomSeed = 1577;

    WorldsMap mainWorldMap;
    mainWorldMap.generate(worldsSettings);

    MainWindow mainWindow(&mainWorldMap);
    mainWindow.show();
 
    return app.exec();
}
