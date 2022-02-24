#pragma once
#include <cmath>
#include <vector>
#include "complex.h"

using namespace std;

const double pi = atan(1) * 4;

inline vector <ComplexNum> dft(vector <double> x, int size = 0)
{
	if (size == 0) size = x.size();
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