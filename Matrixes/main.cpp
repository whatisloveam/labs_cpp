#include <iostream>
#include "Matrix3x3.h"
#include "MatrixXnX.h"
#include <time.h>

using namespace std;

void FirstTask();
void SecondTask();

void FirstTask() // 3x3 matrix static memory
{
	Matrix3x3 matrix;
	matrix.fillRandomElements(-10, 10);//create matrix

    for (auto i = 0; i < matrix.getDimension(); i++) // Print matrix
	{
		for (auto j = 0; j < matrix.getDimension(); j++)
			cout << matrix.element(i, j) << " ";
		cout << endl;
	}

    cout << 
    "Diagonal sum:" << endl <<
        "Principal\t" << matrix.sumPrincipalDiag() << "\tSecondary\t" << matrix.sumSecondaryDiag() << endl <<
    "Diag product:" << endl <<
        "Principal\t" << matrix.productPrincipalDiag() << "\tSecondary\t" << matrix.productSecondaryDiag() << endl <<
    "String sum:" << endl;
    for (auto i = 0; i < matrix.getDimension(); i++)
        cout << i << ":\t" << matrix.sumRow(i) << endl;
    cout << "Column max:" << endl;
    for (auto j = 0; j < matrix.getDimension(); j++)
        cout << j << ":\t" << matrix.maxColumn(j) << endl;
    cout << "Column min:" << endl;
    for (auto j = 0; j < matrix.getDimension(); j++)
        cout << j << ":\t" << matrix.minColumn(j) << endl;
    cout << "________________________" << endl;
}

void SecondTask() // NxN matrix dynamic memory
{
    MatrixXnX matrix = MatrixXnX(4);

    matrix.fillRandomElements(-10, 10);//create matrix

    for (auto i = 0; i < matrix.getDimension(); i++) // Print matrix
    {
        for (auto j = 0; j < matrix.getDimension(); j++)
            cout << matrix.element(i, j) << " ";
        cout << endl;
    }

    cout <<
    "Diagonal sum:" << endl <<
        "Principal\t" << matrix.sumPrincipalDiag() << "\tSecondary\t" << matrix.sumSecondaryDiag() << endl <<
    "Diag product:" << endl <<
        "Principal\t" << matrix.productPrincipalDiag() << "\tSecondary\t" << matrix.productSecondaryDiag() << endl <<
        "String sum:" << endl;
    for (auto i = 0; i < matrix.getDimension(); i++)
        cout << i << ":\t" << matrix.sumRow(i) << endl;
    cout << "Column max:" << endl;
    for (auto j = 0; j < matrix.getDimension(); j++)
        cout << j << ":\t" << matrix.maxColumn(j) << endl;
    cout << "Column min:" << endl;
    for (auto j = 0; j < matrix.getDimension(); j++)
        cout << j << ":\t" << matrix.minColumn(j) << endl;
    cout << "________________________" << endl;
}

int main()
{
	FirstTask();
	SecondTask();

	return 0;
}