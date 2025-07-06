#include "MainWindow.h"

MainWindow::MainWindow(WorldsMap *world)
{
    this->world = world;

    mainView.resize(640, 480);  // TODO : убрать хардкод...
    setCentralWidget(&mainView);

    update();
}

MainWindow::~MainWindow()
{
    
}