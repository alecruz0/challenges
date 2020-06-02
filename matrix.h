#include <stdlib.h>
#include <stdio.h>

/**
 * Creates a empty matrix with the given rows and columns.
 *
 * @param rows - number of rows of matrix
 * @param columns - number of columns of matrix
 *
 * @return new empty matrix
 */
int** create_matrix(int rows, int columns);

/**
 * Destroys the matrix.
 *
 * @param matrix - Matrix to be destroyed
 * @param rows - rows of the matrix
 * @param columns - columns of the matrix
 */
void destroy_matrix(int** matrix, int rows, int columns);

/**
 * Prints the given matrix to the standard output
 *
 * @param matrix - matrix to be printed
 * @param rows - rows of the matrix
 * @param columns - columns of the matrix
 */
void print_matrix(int** matrix, int rows, int columns);
