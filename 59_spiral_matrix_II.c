#include <stdlib.h>

int **generateMatrix(int n)
{
	if (n < 1)
		return(NULL);
	int	**m;
	int	left, right, up, down, i, k;

	m = malloc(n * sizeof(m[0]));
	for (i = 0; i < n; i++)
		m[i] = malloc(n * sizeof(m[0][0]));
	k = 1;
	left = up = 0;
	right = down = n - 1;
	while (left < right) {
		for (i = left; i < right; i++)
			m[up][i] = k++;
		for (i = up; i < down; i++)
			m[i][right] = k++;
		for (i = right; i > left; i--)
			m[down][i] = k++;
		for (i = down; i > up; i--)
			m[i][left] = k++;
		left++;
		right--;
		up++;
		down--;
	}
	if (left == right)
		m[left][right] = k++;
	return(m);
}

int main(void)
{
}
