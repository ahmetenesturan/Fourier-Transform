#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "complex.hpp"
#include "fourier.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
	int menu_input = 0;
	while (true)
	{
		std::cout << "Welcome to the Fourier Transformer, please select an option to continue:" << endl;
		std::cout << "1. Discrete Fourier Transform using an input file." << endl;
		std::cout << "0. Exit program." << endl;
		cin >> menu_input;
		if (menu_input == 0)
		{
			cout << "Ahmet Enes TURAN";
			break;
		}
		if(menu_input == 1)
		{
			string line;
			std::ifstream in_file("input.txt");
			std::ofstream out_file("output.txt", std::ios::trunc);
			vector <double> in;

			while (getline(in_file, line)) in.push_back((stod(line)));

			vector <ComplexNum> A = dft(in);
			for (ComplexNum v : A)
			{
				string s = v.print();
				out_file << s << endl;
			}
			in_file.close();
			out_file.close();
			std::cout << "DFT has produced the output file as \"output.txt\"" << endl;
		}
	}
}