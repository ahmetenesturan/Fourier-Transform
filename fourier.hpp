#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

static const double pi = atan(1) * 4;

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
		//std::cout << std::endl << real << " + j * " << imag << std::endl;
		string s = to_string(real) + " + j * " + to_string(imag);
		return s;
	}
};

inline ComplexNum complexExp(double a)
{
	ComplexNum r = ComplexNum(cos(a), sin(a));
	return r;
}

//inline ComplexNum* dft(double* x, int size)
inline ComplexNum* dft(vector <double> x, int size)
{
	//int size = sizeof(x) / sizeof(double);
	ComplexNum* X = new ComplexNum[size];
	//ComplexNum W = complexExp(-2 * pi / size);
	for (int k = 0; k < size; k++)
	{
		for (int n = 0; n < size; n++)
		{
			X[k] = X[k] + complexExp(-2 * pi * n * k / size) * x[n];
		}
	}
	return X;
}