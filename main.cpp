#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include "fourier.hpp"

using namespace std;

int main()
{
	int menu_input = 0;
	//string dummy;
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
			//std::cout << endl << "Please put your input file as \"input.txt\" to the program directory and press any button the continue..." << endl;
			//cin >> dummy;
			string line;
			ifstream in_file("input.txt");
			ofstream out_file("output.txt", ios::trunc);
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