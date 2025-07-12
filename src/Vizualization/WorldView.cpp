#include "WorldView.h"

const uint32_t bytesPerPixel = 4;

WorldView::WorldView()
{

    imageWidth = 500;
    imageHeight = 500;
    imageArray = new uint8_t[imageHeight*imageWidth*bytesPerPixel];

    image.load("../tmp.png");
}

WorldView::~WorldView()
{
    delete [] imageArray;
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

void WorldView::drawWorld(WorldsMap *world)
{
    uint32_t height, width;
    height = world->height();
    width = world->width();

    uint8_t R, G, B, A;
    A = 255;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (world->getHeightsMatrix()->at(i, j) == 0)
            {
                R = 0; G = 0; B = 255;
            }
            else
            {
                R = 41; G = 94; B = 22;
            }

            if (world->getSandMatrix()->at(i, j) != 0)
            {
                R = 255; G = 249; B = 82;
            }
            setPixelColor(i, j, R, G, B, A);
        }
    }

    image = QImage(imageArray, imageWidth, imageHeight, bytesPerPixel*imageWidth, QImage::Format_ARGB32);
    update();
}

void WorldView::setPixelColor(uint32_t posY, uint32_t posX, uint8_t R, uint8_t G, uint8_t B, uint8_t A)
{
    uint32_t firstPixelsIndex = (posY * imageWidth + posX) * bytesPerPixel; 
    imageArray[firstPixelsIndex + 0] = B;
    imageArray[firstPixelsIndex + 1] = G;
    imageArray[firstPixelsIndex + 2] = R;
    imageArray[firstPixelsIndex + 3] = A;
}