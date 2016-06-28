#include <stdlib.h>

struct NumMatrix {
	int **sum;
};

/** Initialize your data structure here. */
struct NumMatrix* NumMatrixCreate(int** matrix, int matrixRowSize,
		int matrixColSize)
{
	int i, j;
	struct NumMatrix *nummat = malloc(sizeof(*nummat));
	nummat->sum = malloc(matrixRowSize * sizeof(int *));
	for (i = 0; i < matrixRowSize; i++)
		nummat->sum[i] = malloc(matrixColSize * sizeof(int));
	for (i = 0; i < matrixRowSize; i++) {
		for (j = 0; j < matrixColSize; j++) {
			if (i == 0 && j == 0)
				nummat->sum[i][j] = matrix[i][j];
			else if (i == 0)
				nummat->sum[i][j] = matrix[i][j] +
					nummat->sum[i][j - 1];
			else if (j == 0)
				nummat->sum[i][j] = matrix[i][j] +
					nummat->sum[i - 1][j];
			else
				nummat->sum[i][j] = matrix[i][j] +
					nummat->sum[i][j - 1] +
					nummat->sum[i - 1][j] -
					nummat->sum[i - 1][j - 1];
		}
	}
	return(nummat);
}

static int sum(int **summat, int r, int c)
{
	if (r < 0 || c < 0)
		return(0);
	else
		return(summat[r][c]);
}

int sumRegion(struct NumMatrix* numMatrix, int row1, int col1, int row2,
		int col2)
{
	int **t = numMatrix->sum;
	return(sum(t, row2, col2) - sum(t, row2, col1 - 1) -
			sum(t, row1 - 1, col2) +
			sum(t, row1 - 1, col1 - 1));
}

/** Deallocates memory previously allocated for the data structure. */
void NumMatrixFree(struct NumMatrix* numMatrix)
{
	free(numMatrix->sum);
	free(numMatrix);
}

#include <stdio.h>

int main(void)
{
	int a[] = { 1, 2, 3, };
	int b[] = { 4, 5, 6, };
	int c[] = { 7, 8, 9, };
	int *d[] = { a, b, c, };
	struct NumMatrix *mat = NumMatrixCreate(d, 3, 3);
	printf("%d\n", sumRegion(mat, 1, 1, 2, 2));
	NumMatrixFree(mat);
}
