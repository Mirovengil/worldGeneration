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

void WorldView::drawMatrix(Matrix <uint8_t> *matrix)
{
    uint8_t R, G, B, A;
    A = 255;
    for (int i = 0; i < matrix->height(); ++i)
    {
        for (int j = 0; j < matrix->width(); ++j)
        {
            if (matrix->at(i, j) == 0)
            {
                R = 0; G = 0; B = 255;
            }
            else
            {
                R = 0; G = 255; B = 0;
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