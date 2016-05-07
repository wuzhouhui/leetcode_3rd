int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridRowSize,
		int obstacleGridColSize)
{
	if (obstacleGridRowSize < 1 || obstacleGridColSize < 1)
		return(0);

	static mat[100][100];
	int	i, j;

	for (i = 0; i < obstacleGridRowSize; i++) {
		for (j = 0; j < obstacleGridColSize; j++) {
			if (obstacleGrid[i][j]) {
				mat[i][j] = 0;
				continue;
			}
			if (i == 0 && j == 0) {
				mat[i][j] = 1;
				continue;
			}
			if (i == 0) {
				mat[i][j] = mat[i][j - 1];
				continue;
			}
			if (j == 0) {
				mat[i][j] = mat[i - 1][j];
				continue;
			}
			mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
		}
	}
	return(mat[obstacleGridRowSize - 1][obstacleGridColSize - 1]);
}

int main(void)
{
}
