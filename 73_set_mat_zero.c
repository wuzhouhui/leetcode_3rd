#include <string.h>

void setZeroes(int **matrix, int matrixRowSize, int matrixColSize)
{
	int	i, j, firstrow, firstcol;

	firstrow = 0;
	for (i = 0; i < matrixColSize; i++)
		if (!matrix[0][i]) {
			firstrow = 1;
			break;
		}
	firstcol = 0;
	for (i = 0; i < matrixRowSize; i++)
		if (!matrix[i][0]) {
			firstcol = 1;
			break;
		}
	for (i = 1; i < matrixColSize; i++) {
		for (j = 0; j < matrixRowSize; j++)
			if (matrix[j][i])
				continue;
			else {
				matrix[0][i] = 0;
				break;
			}
	}
	for (i = 1; i < matrixRowSize; i++) {
		for (j = 0; j < matrixColSize; j++)
			if (matrix[i][j])
				continue;
			else {
				matrix[i][0] = 0;
				break;
			}
	}
	for (i = 1; i < matrixColSize; i++) {
		if (matrix[0][i])
			continue;
		for (j = 0; j < matrixRowSize; j++)
			matrix[j][i] = 0;
	}
	for (i = 1; i < matrixRowSize; i++) {
		if (matrix[i][0])
			continue;
		memset(matrix[i], 0, matrixColSize * sizeof(int));
	}
	if (firstrow)
		memset(matrix[0], 0, matrixColSize * sizeof(int));
	if (firstcol)
		for (i = 0; i < matrixRowSize; i++)
			matrix[i][0] = 0;
}

int main(void)
{
}
