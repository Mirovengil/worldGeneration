#include "WorldView.h"

WorldView::WorldView()
{
    image.load("../tmp.png");
}

WorldView::~WorldView()
{

}

QSize WorldView::sizeHint() const
{
    return image.size();
}

void WorldView::paintEvent(QPaintEvent *)
{
    painter.begin(this);
    painter.drawImage(0, 0, image);
    painter.end();
}