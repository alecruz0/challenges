#include <iostream>

using namespace std;

#include "matrix.h"

/**
 * Constructor and destructor of Matrix
 */
 
Matrix::Matrix(int rows, int columns) {
	this->rows = rows;
	this->columns = columns;
	allocateMemory();
}

Matrix::~Matrix() {
	deallocateMemory();
}

/**
 * Private
 */
 
void Matrix::allocateMemory() {
	values = new int*[rows];
	for (int r = 0; r < rows; r++)
		values[r] = new int[columns];
}

void Matrix::deallocateMemory() {
	for (int r = 0; r < rows; r++)
		delete[] values[r];
	delete[] values;
}

/**
 * Public
 */

int Matrix::get(int row, int column) {
	if (row > rows || column > column)
		throw out_of_range("Matrix - get - Out of range");
		
	if (row < 0 || column < 0)
		throw out_of_range("Matrix - get - Out of range");
		
	return values[row][column];
}

void Matrix::set(int row, int column, int value) {
	if (row >= rows || column >= columns)
		throw out_of_range("Matrix - get - Out of range");
		
	if (row < 0 || column < 0)
		throw out_of_range("Matrix - get - Out of range");
		
	values[row][column] = value;
}

void Matrix::setValues(int** array) {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++)
			values[r][c] = array[r][c];
	}
}

int Matrix::getRows() {
	return rows;
}

int Matrix::getColumns() {
	return columns;
}

void Matrix::rotate(int rotations) {

	// variables to be used
	int start_row; 
	int end_row;
	
	int start_column; 
	int end_column;
	 
	int previous_value; 
	int next_value;
	
	// loop of rotations
	for (int curr_rot = 0; curr_rot < rotations; curr_rot++) {
		start_row = 0;
		end_row = rows - 1;
		start_column = 0;
		end_column = columns - 1;
		
		// rotate until the start and end of columns passed each other
		// meaning start with outter layer then with inner layers
		while (start_row < end_row || start_column < end_column) {
			previous_value = values[start_row][start_column];
			
			// make left of matrix to move down
			for (int r = start_row; r < end_row; r++) {
				next_value = values[r + 1][start_column];
				values[r + 1][start_column] = previous_value;
				previous_value = next_value;
			}
			
			// make bottom of matrix to move right
			for (int c = start_column; c < end_column; c++) {
				next_value = values[end_row][c + 1];
				values[end_row][c + 1] = previous_value;
				previous_value = next_value;
			}
			
			// make right of matrix move up
			for (int r = end_row; r > start_row; r--) {
				next_value = values[r - 1][end_column];
				values[r - 1][end_column] = previous_value;
				previous_value = next_value;
			}
			
			// make top of matrix to move left
			for (int c = end_column; c > start_column; c--) {
				next_value = values[start_row][c - 1];
				values[start_row][c - 1] = previous_value;
				previous_value = next_value;
			}
			
			// move to inner layer
			start_row++;
			end_row--;
			start_column++;
			end_column--;
		}
	}
}

void Matrix::print() {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++)
			cout << values[r][c] << " ";
		cout << "\n";
	}
}






