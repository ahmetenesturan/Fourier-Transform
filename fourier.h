<<<<<<< HEAD
=======
#pragma once
>>>>>>> a69a35e53e5454975eb6d83a01fd8952185835c3
#include <cmath>
#include <vector>
#include "complex.h"

using namespace std;

const double pi = atan(1) * 4;

<<<<<<< HEAD
vector <ComplexNum> dft(vector <double> x, int size = 0)
{
	if (size == 0) size = (int) x.size();
=======
inline vector <ComplexNum> dft(vector <double> x, int size = 0)
{
	if (size == 0) size = x.size();
>>>>>>> a69a35e53e5454975eb6d83a01fd8952185835c3
	vector <ComplexNum> out;
	ComplexNum c;
	for (int k = 0; k < size; k++)
	{
		c.real = 0;
		c.imag = 0;
		for (int n = 0; n < size; n++)
		{
			c = c + complexExp(-2 * pi * n * k / size) * x[n];
		}
		out.push_back(c);
	}
	return out;
}