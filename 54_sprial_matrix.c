#include <stdlib.h>

int *spiralOrder(int **matrix, int matrixRowSize, int matrixColSize)
{
	int	*res, p;
	int	i, left, right, up, down;

	if (matrixRowSize == 0 || matrixColSize == 0)
		return(NULL);

	res = malloc(matrixRowSize * matrixColSize * sizeof(res[0]));
	p = 0;
	left = up = 0;
	right = matrixColSize - 1;
	down = matrixRowSize - 1;
	while (left < right && up < down) {
		for (i = left; i < right; i++)
			res[p++] = matrix[up][i];
		for (i = up; i < down; i++)
			res[p++] = matrix[i][right];
		for (i = right; i > left; i--)
			res[p++] = matrix[down][i];
		for (i = down; i > up; i--)
			res[p++] = matrix[i][left];
		left++;
		right--;
		up++;
		down--;
	}

	if (left == right && up == down)
		res[p++] = matrix[up][left];
	else if (left == right) {
		while (up <= down)
			res[p++] = matrix[up++][left];
	} else if (up == down) {
		while (left <= right)
			res[p++] = matrix[up][left++];
	}
	return(res);
}

int main(void)
{
	int a[] = { 1, 2, 3, };
	int b[] = { 4, 5, 6, };
	int c[] = { 7, 8, 9, };
	int *d[] = { a, b, c, };
	int *res = spiralOrder(d, 3, 3);
}
