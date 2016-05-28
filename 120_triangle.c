int minimumTotal(int **triangle, int triangleRowSize, int *triangleColSizes)
{
	if (triangleRowSize <= 0)
		return(0);
	int	i, j;
	for (i = 1; i < triangleRowSize; i++) {
		for (j = 0; j < triangleColSizes[i]; j++) {
			if (j == 0)
				triangle[i][j] += triangle[i - 1][j];
			else if (j == triangleColSizes[i] - 1)
				triangle[i][j] += triangle[i - 1][j - 1];
			else
				triangle[i][j] += triangle[i - 1][j] <
					triangle[i - 1][j - 1] ?
					triangle[i - 1][j] :
					triangle[i - 1][j - 1];
		}
	}
	i = triangle[triangleRowSize - 1][0];
	for (j = 1; j < triangleColSizes[triangleRowSize - 1]; j++)
		if (triangle[triangleRowSize - 1][j] < i)
			i = triangle[triangleRowSize - 1][j];
	return(i);
}

#include <stdio.h>

int main(void)
{
	int a[] = { 2 };
	int b[] = { 3, 4, };
	int c[] = { 6, 5, 7, };
	int d[] = { 4, 1, 8, 3, };
	int *e[] = { a, b, c, d, };
	int col[] = { 1, 2, 3, 4, 5, };
	printf("%d\n", minimumTotal(e, 4, col));
}
