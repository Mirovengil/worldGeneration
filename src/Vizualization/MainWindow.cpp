#include "MainWindow.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include <QDebug> // TODO : удоли меня!
#include <time.h> // и меня...

MainWindow::MainWindow(WorldsMap *world)
{
    this->world = world;

    setFixedSize(500, 500);
    mainView.resize(500, 500);  // TODO : убрать хардкод...
    setCentralWidget(&mainView);

    update();

    // начальные настройки мира
    worldsSettings.matrixHeight = 500;
    worldsSettings.matrixWidth = 500;
    worldsSettings.randomSeed = time(0);
    worldsSettings.percentOfSand = 150;
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Space:
            world->processHeightMatrix();
            break;
        case Qt::Key_I:
            world->initWorld(worldsSettings);
            break;
        case Qt::Key_M:
            world->doMedianFiltrationForMatrixOfHeights(3); // TODO : параметризуй эту шнягу...            
            break;
        case Qt::Key_E:
            close();
            break;
        default:
            return;
    }
    mainView.drawWorld(world);

}