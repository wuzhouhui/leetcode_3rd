static void do_trans(char **grid, int r, int c, int row, int col)
{
	if (r < 0 || r >= row || c < 0 || c >= col)
		return;
	if (grid[r][c] != '1')
		return;
	grid[r][c] = '#';
	do_trans(grid, r - 1, c, row, col);
	do_trans(grid, r + 1, c, row, col);
	do_trans(grid, r, c - 1, row, col);
	do_trans(grid, r, c + 1, row, col);
}

int numIslands(char **grid, int gridRowSize, int gridColSize)
{
	int res, i, j;
	for (i = res = 0; i < gridRowSize; i++) {
		for (j = 0; j < gridColSize; j++) {
			if (grid[i][j] != '1')
				continue;
			res++;
			do_trans(grid, i, j, gridRowSize, gridColSize);
		}
	}
	return(res);
}

main(){}
