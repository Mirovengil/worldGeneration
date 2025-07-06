#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include "WorldView.h"

#include "WorldsMap.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(WorldsMap *world);
    ~MainWindow();

private:
    WorldView mainView;

    WorldsSettings worldsSettings;
    WorldsMap *world;

    void initMenu();
    
    void keyPressEvent(QKeyEvent *event);
};

#endif