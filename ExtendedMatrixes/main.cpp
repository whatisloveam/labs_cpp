/*
Author: Vladislav Melnikov

RI-280001
*/
#include "Matrix2D.h"
#include "Matrix3D.h"
#include <iostream>

using namespace std;

int main()
{
    Matrix2D m2a, m2b;
    Matrix3D m3a, m3b;

    cout << "m2a: \n" << m2a << endl;
    cout << "m2b: \n" << m2b << endl;

    cout << "m3a: \n" << m3a << endl;
    cout << "m3b: \n" << m3b << endl;

    m2a += m2b;
    cout << "m2a + m2b: \n" << m2a << endl;

    m2b *= 4;
    cout << "m2b * 4: \n" << m2b << endl;

    m3a += m3a;
    cout << "m3a + m3a: \n" << m3a << endl;

    m3b *= 3;
    cout << "m3b * 3: \n" << m3b << endl;

    return 0;
}