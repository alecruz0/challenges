#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "matrix.h"
#include "utilities.h"

/**
 * @Author: Manuel Cruz
 * @Date June 2, 2020
 * @Description: Given a matrix rotate it counterclockwise
 *				 from the center of it.
 *
 * @Example:
 * Rotate it 2 times
 * Given Matrix:
 * 1 2 3
 * 4 5 6
 * 7 8 9
 *
 * Resulted Matrix:
 * 3 6 9
 * 2 5 8
 * 1 4 7
 */


/**
 * Rotates the given matrix with the given number of rotations.
 *
 * @param matrix - given matrix to be rotated.
 * @param rows - number of rows of matrix.
 * @param columns - number of columns of matrix.
 * @param rotations - number of rotations to give to matrix.
 */
void rotate(int** matrix, int rows, int columns, int rotations);

/**
 * Main method.
 *
 * @param argc - number of args
 * @param argv - vector of args
 *
 * @return process status
 */
int main (int argc, char** argv)
{
	// check the number of args
	if (argc != 4)
	{
		usage();
		return -1;
	}

	// get user args
	int rows = atoi(argv[1]);
	int columns = atoi(argv[2]);
	int rotations = atoi(argv[3]);
	
	// create empty matrix
	int** matrix = create_matrix(rows, columns);
	
	// fill the matrix
	generate_matrix(matrix, rows, columns);

	printf("Before Rotation:\n");
	print_matrix(matrix, rows, columns);
	
	// rotate the matrix
	rotate(matrix, rows, columns, rotations);
	
	printf("After Rotation:\n");
	print_matrix(matrix, rows, columns);
	
	// release memeory of matrix
	destroy_matrix(matrix, rows, columns);
	
	return 0;
}

void rotate(int** matrix, int rows, int columns, int rotations)
{
	// variables to be used
	int start_row, end_row, start_column, end_column, 
	previous_value, next_value;
	
	// loop of rotations
	for (int current_rotation = 0; current_rotation < rotations; current_rotation++)
	{
		start_row = 0;
		end_row = rows - 1;
		start_column = 0;
		end_column = columns - 1;
		
		// rotate until the start and end of columns passed each other
		// meaning start with outter layer then with inner layers
		while (start_row < end_row || start_column < end_column)
		{
			previous_value = matrix[start_row][start_column];
			
			// make left of matrix to move down
			for (int r = start_row; r < end_row; r++) {
				next_value = matrix[r + 1][start_column];
				matrix[r + 1][start_column] = previous_value;
				previous_value = next_value;
			}
			
			// make bottom of matrix to move right
			for (int c = start_column; c < end_column; c++) {
				next_value = matrix[end_row][c + 1];
				matrix[end_row][c + 1] = previous_value;
				previous_value = next_value;
			}
			
			// make right of matrix move up
			for (int r = end_row; r > start_row; r--) {
				next_value = matrix[r - 1][end_column];
				matrix[r - 1][end_column] = previous_value;
				previous_value = next_value;
			}
				
			// make top of matrix to move left
			for (int c = end_column; c > start_column; c--) {
				next_value = matrix[start_row][c - 1];
				matrix[start_row][c - 1] = previous_value;
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



























