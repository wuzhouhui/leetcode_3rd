static void trans(char **board, int r, int c, int row, int col)
{
	if (r < 0 || r >= row || c < 0 || c >= col || board[r][c] != 'O')
		return;
	board[r][c] = '#';
	if (c != 0 && c != col - 1) {
		trans(board, r - 1, c, row, col);
		trans(board, r + 1, c, row, col);
	}
	if (r != 0 && r != row - 1) {
		trans(board, r, c - 1, row, col);
		trans(board, r, c + 1, row, col);
	}
}

void solve(char **board, int boardRowSize, int boardColSize)
{
	int i, j;
	for (j = 0; j < boardColSize; j++) {
		if (board[0][j] == 'O')
			trans(board, 0, j, boardRowSize, boardColSize);
		if (board[boardRowSize - 1][j] == 'O')
			trans(board, boardRowSize - 1, j, boardRowSize,
					boardColSize);
	}
	for (i = 0; i < boardRowSize; i++) {
		if (board[i][0] == 'O')
			trans(board, i, 0, boardRowSize, boardColSize);
		if (board[i][boardColSize - 1])
			trans(board, i, boardColSize - 1, boardRowSize,
					boardColSize);
	}
	for (i = 0; i < boardRowSize; i++) {
		for (j = 0; j < boardColSize; j++) {
			if (board[i][j] == 'X')
				continue;
			else if (board[i][j] == 'O')
				board[i][j] = 'X';
			else /* '#' */
				board[i][j] = 'O';
		}
	}
}

int main(void)
{
}
