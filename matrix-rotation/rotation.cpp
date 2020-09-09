#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "matrix.h"

/**
 * Prints usage of program to screen.
 */
void usage() {
	cout << "Usage:\n";
	cout << "\t./rotation filename\n";
}

/**
 * Splits a string between spaces in the given matrix file.
 *
 * @param stringToSplit - string that will be splitted
 *
 * @return a vector containing the splitted strings
 */
vector<string> split(string stringToSplit) {
	vector<string> vector;
	
	string substring = "";
	
	for (int i = 0; i < stringToSplit.size(); i++) {
		if (stringToSplit[i] == ' ' && !substring.empty()) {
			vector.push_back(substring);
			substring = "";
		} else if (i + 1 == stringToSplit.size()) {
			substring += stringToSplit[i];
			vector.push_back(substring);
		} else {
			substring += stringToSplit[i];
		}
	}

	return vector;
}

/**
 * Main starting point of the program.
 *
 * @param argc - count of arguments
 * @param argv - vector of args
 *
 * @return process status.
 */
int main(int argc, char* argv[]) {

	// check the number of args
	if (argc != 2) {
		usage();
		return -1;
	}
	
	// open the file for reading
	fstream file;
	file.open(argv[1], ios::in);
	if (!file.is_open()) {
		cout << argv[1] << " could not be open\n";
		return -1;
	}
	
	// read the first line of the file
	string line;
	getline(file, line);
	
	// split the header
	vector<string> values = split(line);
	
	// check the number of header values
	if (values.size() != 3)
	{
		cout << "Invalid header in file\n";
		cout << "File header should include rows columns rotation\n";
		file.close();
		return -1;
	}
	
	// read values of header
	int rows = stoi(values.at(0));
	int columns = stoi(values.at(1));
	int rotations = stoi(values.at(2));
	
	// create empty matrix
	Matrix matrix(rows, columns);
	
	
	// read values from file.
	for (int r = 0; r < rows; r++) {
		getline(file, line);
		values = split(line);
		for (int c = 0; c < columns; c++) {
			matrix.set(r, c, stoi(values.at(c)));
		}
	}
	
	// close file 
	file.close();
	
	cout << "Before Rotation:\n";
	matrix.print();
	cout << endl;
	
	// rotate
	matrix.rotate(rotations);
	
	cout << "After Rotation:\n";
	matrix.print();
	
	return 0;
}
