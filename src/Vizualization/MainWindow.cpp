#include "MainWindow.h"
#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include <QDebug> // TODO : удоли меня!
#include <time.h> // и меня...

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
    worldsSettings.randomSeed = time(0);
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
            world->initHeightMatrix(worldsSettings);
            mainView.drawMatrix(world->getHeightsMatrix());
        });
    connect(closeApplicationAction, &QAction::triggered, this, &MainWindow::close);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        world->processHeightMatrix();
        mainView.drawMatrix(world->getHeightsMatrix());
    }
}