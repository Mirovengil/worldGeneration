#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>
#include <string.h>
#include <stdexcept>

template <typename Type>
class Matrix
{
private:
    Type** data = nullptr;
    uint32_t verticalSize = 0;
    uint32_t horizontalSize = 0;

public:
    Matrix()
    {
    }
    
    ~Matrix()
    {
        clearData();
    }

    void clearData()
    {
        if (data == nullptr)
            return;

        for (uint32_t i = 0; i < verticalSize; ++i)
            delete [] data[i];
        delete [] data;

        data = nullptr;
    }

    void resize(uint32_t height, uint32_t width)
    {
        clearData();
        
        verticalSize = height;
        horizontalSize = width;

        data = new Type*[verticalSize];
        for (uint32_t i = 0; i < verticalSize; ++i)
            data[i] = new Type[horizontalSize];
    }

    Type& at(int vertical, int horizontal)
    {
        return data[vertical][horizontal];
    }

    uint32_t height()
    {
        return verticalSize;
    }

    uint32_t width()
    {
        return horizontalSize;
    }

    void fillDataWithZeros()
    {
        for (int w = 0; w < verticalSize; ++w)
            memset(data[w], 0, sizeof(Type)*horizontalSize);
    }

    void copyTo(Matrix<Type> *other)
    {
        if (other->width() != width())
            throw std::range_error("Matrix::copyTo: matrixes has the different horizontal dimensions (widths)!");
        if (other->height() != height())
            throw std::range_error("Matrix::copyTo: matrixes has the different horizontal dimensions (heights)!");

        for (int v = 0; v < verticalSize; ++v)
        {
            for (int h = 0; h < horizontalSize; ++h)
            {
                other->at(v, h) = data[v][h];
            }
        }
    }
};

#endif 