#include "MainWindow.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(WorldsMap *world)
{
    this->world = world;

    mainView.resize(640, 480);  // TODO : убрать хардкод...
    setCentralWidget(&mainView);

    initMenu();

    update();

    // начальные настройки мира
    worldsSettings.matrixHeight = 500;
    worldsSettings.matrixWidth = 500;
    worldsSettings.randomSeed = 1577;
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::initMenu()
{
    QAction *initNewWorldAction = new QAction(tr("INIT"));
    QAction *closeApplicationAction = new QAction(tr("EXIT"));

    menuBar()->addAction(initNewWorldAction);
    menuBar()->addAction(closeApplicationAction);

    connect(initNewWorldAction, &QAction::triggered, this, 
        [=](){
            world->init(worldsSettings);
            mainView.drawMatrix(world->getHeightsMatrix());
        });
    connect(closeApplicationAction, &QAction::triggered, this, &MainWindow::close);
}