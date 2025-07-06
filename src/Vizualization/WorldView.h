#ifndef WORLD_VIEW_H
#define WORLD_VIEW_H

#include <QWidget>
#include <QImage>
#include <QPainter>

#include <stdint.h>

class WorldView : public QWidget
{
Q_OBJECT

private:
    QImage image;
    QPainter painter;
public:
    WorldView();
    ~WorldView();
    
    QSize sizeHint() const override;
    void paintEvent(QPaintEvent *) override;
};

#endif