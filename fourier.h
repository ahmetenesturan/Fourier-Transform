#pragma once
#include "fourier.cpp"

extern const double pi;

inline ComplexNum complexExp(double a);

inline vector <ComplexNum> dft(vector <double> x, int size);