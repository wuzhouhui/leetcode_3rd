#include <string.h>

static int isvalid(char **board, char row, char col)
{
	static char nums[10];
	int	i, j;

	memset(nums, 0, sizeof(nums));
	for (i = 0; i < 9; i++) {
		if (board[row][i] == '.')
			continue;
		if (nums[board[row][i] - '1'])
			return(0);
		nums[board[row][i] - '1'] = board[row][i];
	}
	memset(nums, 0, sizeof(nums));
	for (i = 0; i < 9; i++) {
		if (board[i][col] == '.')
			continue;
		if (nums[board[i][col] - '1'])
			return(0);
		nums[board[i][col] - '1'] = board[i][col];
	}
	memset(nums, 0, sizeof(nums));
	row /= 3;
	col /= 3;
	for (i = row * 3; i < row * 3 + 3; i++) {
		for (j = col * 3; j < col * 3 + 3; j++) {
			if (board[i][j] == '.')
				continue;
			if (nums[board[i][j] - '1'])
				return(0);
			nums[board[i][j] - '1'] = board[i][j];
		}
	}
	return(1);
}

static int do_solve(char **board, char row, char col)
{
	int	i, j, k;

	if (row >= 9 || col >= 9)
		return(1);

	for (i = row; i < 9; i++) {
		j = (i == row ? col + 1 : 0);
		for (; j < 9; j++) {
			if (board[i][j] != '.')
				continue;
			for (k = '1'; k <= '9'; k++) {
				board[i][j] = k;
				if (!isvalid(board, i, j))
					continue;
				if (do_solve(board, i, j))
					return(1);
			}
			board[i][j] = '.';
			return(0);
		}
	}
	return(1);
}

void solveSudoku(char **board, int boardRowSize, int boardColSize)
{
	do_solve(board, 0, -1);
}

int main(void)
{
	char r1[] = "..9748...";
	char r2[] = "7........";
	char r3[] = ".2.1.9...";
	char r4[] = "..7...24.";
	char r5[] = ".64.1.59.";
	char r6[] = ".98...3..";
	char r7[] = "...8.3.2.";
	char r8[] = "........6";
	char r9[] = "...2759..";

	char *argv[] = {
		r1, r2, r3, r4, r5, r6, r7, r8, r9,
	};
	solveSudoku(argv, 9, 9);
	return(0);
}
