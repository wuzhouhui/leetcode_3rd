int minPathSum(int **grid, int gridRowSize, int gridColSize)
{
	if (gridRowSize < 1 || gridColSize < 1)
		return(0);
	int	i, j;
	for (i = 0; i < gridRowSize; i++) {
		for (j = 0; j < gridColSize; j++) {
			if (i == 0 && j == 0)
				continue;
			if (i == 0) {
				grid[i][j] += grid[i][j - 1];
				continue;
			}
			if (j == 0) {
				grid[i][j] += grid[i - 1][j];
				continue;
			}
			grid[i][j] += (grid[i - 1][j] < grid[i][j - 1] ?
					grid[i - 1][j] : grid[i][j - 1]);
		}
	}
	return(grid[gridRowSize - 1][gridColSize - 1]);
}

int main(void)
{
}
