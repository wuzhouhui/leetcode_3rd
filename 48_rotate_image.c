void rotate(int **matrix, int matrixRowSize, int matrixColSize)
{
	int	up, down, left, right, len, i, t;

	up = 0;
	down = matrixRowSize - 1;
	left = 0;
	right = matrixColSize - 1;
	while (up < down && left < right) {
		len = right - left;
		for (i = 0; i < len; i++) {
			t = matrix[down - i][left];
			matrix[down - i][left] = matrix[down][right - i];
			matrix[down][right - i] = matrix[up + i][right];
			matrix[up + i][right] = matrix[up][left + i];
			matrix[up][left + i] = t;
		}
		up++;
		down--;
		left++;
		right--;
	}
}

int main(void)
{
	int	a[] = {1, 2, };
	int	b[] = { 3, 4, };
	int	*c[] = {a, b};
	rotate(c, 2, 2);
	return(0);
}
