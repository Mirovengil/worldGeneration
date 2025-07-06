#include <QApplication>

// отрисовка
#include "MainWindow.h"

// типы данных
#include "WorldsMap.h"

 // алгоритмы

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    WorldsMap mainWorldMap;

    MainWindow mainWindow(&mainWorldMap);
    mainWindow.show();
 
    return app.exec();
}
