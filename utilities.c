#include "utilities.h"

void usage()
{
	printf("Usage: ./rotation rows columns rotations\n");
}

void generate_matrix(int** matrix, int rows, int columns)
{
	int value = 0;
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
			matrix[r][c] = ++value;
	}
}

