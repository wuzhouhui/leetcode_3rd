int uniquePaths(int m, int n)
{
	if (m < 1 || n < 1)
		return(0);
	static int mat[100][100];
	int	i, j;

	for (i = 0; i < m; i++)
		mat[i][0] = 1;
	for (i = 0; i < n; i++)
		mat[0][i] = 1;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (!i || !j)
				continue;
			mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
		}
	}
	return(mat[m - 1][n - 1]);
}

int main(void)
{
}
