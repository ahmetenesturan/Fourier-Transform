#include <cmath>
#include <vector>
#include "complex.h"

using namespace std;

const double pi = atan(1) * 4;
/*
class ComplexNum
{
public:
	double real;
	double imag;
	ComplexNum(double r, double i)
	{
		real = r;
		imag = i;
	}
	ComplexNum(double r)
	{
		real = r;
		imag = 0;
	}
	ComplexNum()
	{
		real = 0;
		imag = 0;
	}
	ComplexNum& operator+(ComplexNum a)
	{
		ComplexNum r = ComplexNum((this->real + a.real), (this->imag + a.imag));
		return r;
	}
	ComplexNum& operator*(ComplexNum a)
	{
		double real_part = (this->real * a.real) - (this->imag * a.imag);
		double imag_part = (this->real * a.imag) + (this->imag * a.real);
		ComplexNum r = ComplexNum(real_part, imag_part);
		return r;
	}
	string print()
	{
		string s = to_string(real) + " + j * " + to_string(imag);
		return s;
	}
};

inline ComplexNum complexExp(double a)
{
	ComplexNum r = ComplexNum(cos(a), sin(a));
	return r;
}
*/
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