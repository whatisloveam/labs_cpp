#include "MatrixBase.h"

class Matrix2D : public MatrixBase
{
public:
	Matrix2D();
	int element(unsigned int i, unsigned int j) const override;
	int& element(unsigned int i, unsigned int j) override;
private:
	static constexpr int size = 2;
	int matrix[size * size];
};

