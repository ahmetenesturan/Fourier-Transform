#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include "fourier.hpp"

using namespace std;

int main()
{
	string line;
	ifstream in_file("input.txt");
	ofstream out_file("output.txt", ios::trunc);
	vector <double> in;
	int size = 0;

	while (getline(in_file, line))
	{
		in.push_back((stod(line)));
		size++;
	}
	
	
	//double a[] = {1,0,-1,0};
	
	ComplexNum* A = dft(in, size);
	string s = A->print();
	out_file << s;
	A++;
	A->print();
	A++;
	A->print();
	A++;
	A->print();
	//std::cout << sizeof(a) / sizeof(double);
	in_file.close();
	out_file.close();
}

//out file print yapmalý

//ComplexNum'u vector için uyumlu yap