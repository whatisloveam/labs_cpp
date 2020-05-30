#include "MatrixBase.h"
#include <string>

void MatrixBase::operator*=(int iMult) 
{
    for (auto x = 0; x < m_size; x++)
        for (auto y = 0; y < m_size; y++)
            element(x, y) *= iMult;
}

void MatrixBase::operator+=(MatrixBase& iAdd) 
{
    for (auto x = 0; x < iAdd.m_size; x++)
        for (auto y = 0; y < iAdd.m_size; y++)
            element(x, y) += iAdd.element(x, y);
}

std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix)
{
    auto count = iMatrix.size();
    std::string text;
    for (auto i = 0; i < count; i++)
    {
        for (auto j = 0; j < count; j++)
            text += std::to_string(iMatrix.element(i, j)) + " ";
        text += '\n';
    }
    stream << text;
    return stream;
}