#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include <QWidget>
#include <QImage>
#include <QPainter>

#include <stdint.h>

#include "WorldsMap.h"

class WorldView : public QWidget
{
Q_OBJECT

private:
    QImage image;
    QPainter painter;

    uint16_t imageWidth, imageHeight;
    uint8_t *imageArray;
    inline void setPixelColor(uint32_t posY, uint32_t posX, uint8_t R, uint8_t G, uint8_t B, uint8_t A);

public:
    WorldView();
    ~WorldView();
    

    void drawWorld(WorldsMap *world);

    QSize sizeHint() const override;
    void paintEvent(QPaintEvent *) override;
};

#endif