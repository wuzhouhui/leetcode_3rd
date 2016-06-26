static int lives(int **board, int r, int c, int row, int col)
{
	int i, j, ret = 0;
	for (i = r - 1; i <= r + 1; i++) {
		for (j = c - 1; j <= c + 1; j++) {
			if (i == r && j == c)
				continue;
			if (i < 0 || i >= row || j < 0 || j >= col)
				continue;
			if (board[i][j] & 1)
				ret++;
		}
	}
	return(ret);
}

void gameOfLife(int **board, int boardRowSize, int boardColSize)
{
	int i, j, lv;

	for (i = 0; i < boardRowSize; i++) {
		for (j = 0; j < boardColSize; j++) {
			lv = lives(board, i, j, boardRowSize, boardColSize);
			if (board[i][j] & 1) {
				if (lv == 2 || lv == 3)
					board[i][j] |= 2;
			} else if (lv == 3)
				board[i][j] |= 2;
		}
	}
	for (i = 0; i < boardRowSize; i++) {
		for (j = 0; j < boardColSize; j++) {
			board[i][j] >>= 1;
		}
	}
}
main(){}
