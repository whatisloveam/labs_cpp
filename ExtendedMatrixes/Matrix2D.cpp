#include "Matrix2D.h"

Matrix2D::Matrix2D() : MatrixBase(size)
{
	for (auto i = 0; i < size * size; i++)
		matrix[i] = i + 1;
}

int Matrix2D::element(unsigned int i, unsigned int j) const
{
	return matrix[i * size + j];
}

int& Matrix2D::element(unsigned int i, unsigned int j)
{
	return matrix[i * size + j];
}
