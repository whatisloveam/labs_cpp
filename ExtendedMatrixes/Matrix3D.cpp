#include "Matrix3D.h"

Matrix3D::Matrix3D() :MatrixBase(size) 
{
    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
            matrix[x][y] = x * size + y + 1;
};

int Matrix3D::element(unsigned int i, unsigned int j) const
{
    return matrix[i][j];
}

int& Matrix3D::element(unsigned int i, unsigned int j)
{
    return matrix[i][j];
}
