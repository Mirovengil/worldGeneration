#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

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

    Type& operator()(int vertical, int horizontal)
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
};

#endif 