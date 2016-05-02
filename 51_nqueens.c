#include <stdlib.h>
#include <string.h>

static int queens[64][64];
static int occupy[64];
static char ***res;
static int maxp, p;

static void addans(int n)
{
	int	i, j;

	if (!res) {
		maxp = 8;
		res = malloc(maxp * sizeof(*res));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p] = malloc(n * sizeof(char *));
	for (i = 0; i < n; i++) {
		res[p][i] = malloc((n + 1) * sizeof(char));
		for (j = 0; j < n; j++) {
			if (queens[i][j])
				res[p][i][j] = 'Q';
			else
				res[p][i][j] = '.';
		}
		res[p][i][j] = 0;
	}
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

char ***solveNQueens(int n, int *returnSize)
{
	if (n < 1) {
		*returnSize = 0;
		return(NULL);
	}

	res = NULL;
	p = 0;
	memset(occupy, 0, sizeof(occupy));
	memset(queens, 0, sizeof(queens));
	do_queens(n, 0);
	*returnSize = p;
	return(res);
}

int main(void)
{
	int	n;
	char	***q = solveNQueens(4, &n);
	return(0);
}
