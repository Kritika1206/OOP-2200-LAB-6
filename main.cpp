/*
Author: Kritika Singh & Kingsly Bude
Date: 2022-08-10
Purpose: Lab 6: Working with input and output streams
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 
#include "Vaccine.h"

using namespace std;

int main() {
	int size = -1;
	double total = 0;
	ofstream myOutputFile;
	string info = "";
	Vaccine* vaccines;
	Vaccine modernaVaccine;


	ifstream myInputFile("Vaccines.csv");
	if (myInputFile.is_open()) {
		cout << "A Vaccines.csv file was found." << endl;
		while (!myInputFile.eof()) {
			getline(myInputFile, info);
			size++;

		}
		vaccines = new Vaccine[size];

		myInputFile.clear();
		myInputFile.seekg(0);

		if (myInputFile.is_open()) {
			for (int i = 0; i < size; i++) {
				getline(myInputFile, vaccines[i].SKU, ',');
				getline(myInputFile, vaccines[i].name, ',');
				getline(myInputFile, vaccines[i].unitPrice, ',');
				getline(myInputFile, vaccines[i].availableUnits, ',');
				getline(myInputFile, vaccines[i].specialInstructions, '\n');
			}

		}
		myInputFile.close();

		myOutputFile.open("report.txt");
		myOutputFile << "Product                Currency             Cost" << endl;
		for (int i = 0; i < size; i++) {
			myOutputFile << vaccines[i].name << "-" << vaccines[i].SKU << setw(20 - vaccines[i].name.length()) << "C$" << setw(20) << vaccines[i].unitPrice << endl;
			total += stod(vaccines[i].unitPrice);
		}
		myOutputFile << "----------------------------------------------------------------" << endl;
		myOutputFile << "Total                     C$" << setw(20) << total << endl;
		myOutputFile.close();
		cout << "Text file created." << endl << endl;
	}

	else
	{
		cout << "ERROR accessing file." << endl;
	}
	return 0;
}