#pragma once
#include <string>

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
	std::string print()
	{
		std::string s = std::to_string(real) + " + j * " + std::to_string(imag);
		return s;
	}
};

inline ComplexNum complexExp(double a)
{
	ComplexNum r = ComplexNum(cos(a), sin(a));
	return r;
}