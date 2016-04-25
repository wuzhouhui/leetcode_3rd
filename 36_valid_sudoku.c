#ifndef bool
#define bool int
#endif

bool isValidSudoku(char **board, int boardRowSize, int boardColSize)
{
	signed char	nums[9];
	int	i, j, m, n;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++)
			nums[j] = 1;
		for (j = 0; j < 9; j++)
			if (board[i][j] == '.')
				continue;
			else
				nums[board[i][j] - '1']--;
		for (j = 0; j < 9; j++)
			if (nums[j] < 0)
				return(0);
	}

	for (j = 0; j < 9; j++) {
		for (i = 0; i < 9; i++)
			nums[i] = 1;
		for (i = 0; i < 9; i++)
			if (board[i][j] == '.')
				continue;
			else
				nums[board[i][j] - '1']--;
		for (i = 0; i < 9; i++)
			if (nums[i] < 0)
				return(0);
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (m = 0; m < 9; m++)
				nums[m] = 1;
			for (m = 3 * i; m < 3 * i + 3; m++) {
				for (n = 3 * j; n < 3 * j + 3; n++)
					if (board[m][n] == '.')
						continue;
					else
						nums[board[m][n] - '1']--;
			}
			for (m = 0; m < 9; m++)
				if (nums[m] < 0)
					return(0);
		}
	}
	return(1);
}

int main(void)
{
}
