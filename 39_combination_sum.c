#include <stdlib.h>
#include <string.h>

static int **res, *col, *ans;
static int maxp, p, ansmaxp, ansp;

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static void addres(void)
{
	if (!res) {
		maxp = 8;
		res = malloc(maxp * sizeof(*res));
		col = malloc(maxp * sizeof(*col));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
		col = realloc(col, maxp * sizeof(*col));
	}
	res[p] = malloc(ansp * sizeof(*ans));
	memcpy(res[p], ans, ansp * sizeof(*ans));
	col[p] = ansp;
	p++;
}

static void addans(int v)
{
	if (!ans) {
		ansmaxp = 8;
		ans = malloc(ansmaxp * sizeof(*ans));
	}
	if (ansp >= ansmaxp) {
		ansmaxp += 8;
		ans = realloc(ans, ansmaxp * sizeof(*ans));
	}
	ans[ansp++] = v;
}

static void do_combsum(const int *nums, int len, int cursum, int tgt)
{
	int	i, t, oldansp;

	if (cursum == tgt) {
		addres();
		return;
	}

	if (len <= 0)
		return;

	for (i = 0; i < len; i++) {
		if (cursum + nums[i] > tgt)
			return;
		t = cursum;
		oldansp = ansp;
		while ((t + nums[i]) <= tgt) {
			t += nums[i];
			addans(nums[i]);
			do_combsum(nums + i + 1, len - i - 1, t, tgt);
		}
		ansp = oldansp;
	}
}

int **combinationSum(int *candidates, int candidatesSize, int target,
		int **columnSizes, int *returnSize)
{
	res = NULL;
	ans = NULL;
	col = NULL;
	ansp = p = 0;

	qsort(candidates, candidatesSize, sizeof(*candidates), intcmp);
	do_combsum(candidates, candidatesSize, 0, target);
	*columnSizes = col;
	*returnSize = p;
	return(res);
}

int main(void)
{
	int	a[] = { 2, 3, 6, 7, };
	int	*col, n;
	combinationSum(a, sizeof(a) / sizeof(a[0]), 7, &col, &n);
}
