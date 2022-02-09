#include <iostream>
#include <fstream>
#include <cmath>
#include "fourier.hpp"

int main()
{
	
	double a[] = {1,0,-1,0};
	
	ComplexNum* A = dft(a, 4);
	A->print();
	A++;
	A->print();
	A++;
	A->print();
	A++;
	A->print();
	
	//std::cout << sizeof(a) / sizeof(double);
}