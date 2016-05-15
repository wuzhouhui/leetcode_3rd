#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define STEP 8

static int **res, *col, p, maxp;

static int intcmp(const void *x, const void *y)
{
	return(*(int *)x - *(int *)y);
}

static void add_ans(int *t, int n)
{
	int	i;

	for (i = 0; i < p; i++) {
		if (col[i] != n)
			continue;
		if (!memcmp(res[i], t, n * sizeof(int))) {
			free(t);
			return;
		}
	}
	if (p >= maxp) {
		maxp += STEP;
		res = realloc(res, maxp * sizeof(int *));
		col = realloc(col, maxp * sizeof(int));
	}

	res[p] = t;
	col[p] = n;
	p++;
}

int **subsetsWithDup(int *nums, int numsSize, int **columnSizes,
		int *returnSize)
{
	if (!numsSize) {
		*columnSizes = 0;
		*returnSize = 0;
		return(0);
	}

	uint64_t bit;
	uint64_t i;
	int	j, n, k, *t;

	bit = 0;
	for (i = 0; i < ((uint64_t)1 << numsSize); i++, bit++) {
		n = 0;
		for (j = 0; j < numsSize; j++) {
			if (bit & ((uint64_t)1 << j))
				n++;
		}
		if (!n) {
			maxp = STEP;
			p = 0;
			res = malloc(maxp * sizeof(int *));
			col = malloc(maxp * sizeof(int));
			res[p] = 0;
			col[p] = 0;
			p++;
			continue;
		}
		
		t = malloc(n * sizeof(int));
		for (k = 0, j = 0; j < numsSize; j++) {
			if (bit & ((uint64_t)1 << j))
				t[k++] = nums[j];
		}
		qsort(t, n, sizeof(int), intcmp);
		add_ans(t, n);
	}
	*columnSizes = col;
	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(void)
{
	int x[] = { 1, 2, 2 };
	int **res, *col, n;
	res = subsetsWithDup(x, 3, &col, &n);
	printf("%d\n", n);
	return(0);
}
