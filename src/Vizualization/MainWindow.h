#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QWidget>

#include "WorldsMap.h"

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(WorldsMap *world);
    ~MainWindow();
private:
    WorldsMap *world;
};

#endif