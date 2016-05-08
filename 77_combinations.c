#include <stdlib.h>
#include <string.h>

static int **res, *col, *ans;
static int maxp, p;

static void add_ans(int k)
{
	if (!res) {
		maxp = 8;
		res = malloc(maxp * sizeof(int *));
		col = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(int *));
		col = realloc(col, maxp * sizeof(int));
	}
	res[p] = malloc(k * sizeof(int));
	memcpy(res[p], ans, k * sizeof(int));
	col[p] = k;
	p++;
}

static void do_comb(int n, int k, int level, int next)
{
	if (level >= k) {
		add_ans(k);
		return;
	}

	int	i;

	for (i = next; i <= n; i++) {
		if (n - i + 1 < k - level)
			break;
		ans[level] = i;
		do_comb(n, k, level + 1, i + 1);
	}
}

int **combine(int n, int k, int **columnSizes, int *returnSize)
{
	res = 0;
	p = 0;
	ans = malloc(k * sizeof(int));
	do_comb(n, k, 0, 1);
	*returnSize = p;
	*columnSizes = col;
	if (ans)
		free(ans);
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	**res, *col, i, n;
	res = combine(4, 1, &col, &n);
	for (i = 0; i < n; i++)
		printf("%d \n", res[i][0]);
	return(0);
}
