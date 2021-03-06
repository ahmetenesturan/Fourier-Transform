#include <cmath>
#include <vector>
#include "complex.h"

using namespace std;

const double pi = atan(1) * 4;

vector <ComplexNum> dft(vector <double> x, int size = 0)
{
	if (size == 0) size = (int) x.size();
	vector <ComplexNum> out;
	ComplexNum c;
	for (int k = 0; k < size; k++)
	{
		c.real = 0;
		c.imag = 0;
		for (int n = 0; n < size; n++)
		{
			//c = c + complexExp(-2 * pi * n * k / size) * x[n];
			c = c + exp(ComplexNum(0,-2 * pi * n * k / size)) * x[n];
		}
		out.push_back(c);
	}
	return out;
}