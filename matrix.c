
#include "matrix.h"

int** create_matrix(int rows, int columns)
{
	int** matrix = malloc(sizeof(int*) * rows);
	for(int r = 0; r < rows; r++)
		matrix[r] = malloc(sizeof(int) * columns);
	
	return matrix;
}

void destroy_matrix(int** matrix, int rows, int columns)
{
	for (int r = 0; r < rows; r++)
	{
		free(matrix[r]);
	}
	free(matrix);
}

void print_matrix(int** matrix, int rows, int columns)
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			printf("%d ", matrix[r][c]);
		}
		printf("\n");
	}
}
