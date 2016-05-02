#include <stdlib.h>
#include <string.h>

static int queens[64][64];
static int occupy[64];
static char ***res;
static int maxp, p;

static void addans(int n)
{
	p++;
}

static int isvalid(int n, int row, int col)
{
	int	i, j;

	for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if (queens[i][j])
			return(0);
	}
	for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
		if (queens[i][j])
			return(0);
	}
	return(1);
}

static void do_queens(int n, int dep)
{
	int	i;

	if (dep >= n) {
		addans(n);
		return;
	}

	for (i = 0; i < n ; i++) {
		if (occupy[i])
			continue;
		occupy[i] = 1;
		queens[dep][i] = 1;
		if (isvalid(n, dep, i))
			do_queens(n, dep + 1);
		occupy[i] = 0;
		queens[dep][i] = 0;
	}
}

int totalNQueens(int n)
{
	if (n < 1)
		return(0);

	p = 0;
	memset(occupy, 0, sizeof(occupy));
	memset(queens, 0, sizeof(queens));
	do_queens(n, 0);
	return(p);
}

int main(void)
{
	int	n = totalNQueens(0);
	return(0);
}
