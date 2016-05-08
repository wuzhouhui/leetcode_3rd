#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static int intcmp(const void *x, const void *y)
{
	return(*(int *)x - *(int *)y);
}

int **subsets(int *nums, int numsSize, int **columnSizes, int *returnSize)
{
	if (!numsSize) {
		*columnSizes = 0;
		*returnSize = 0;
		return(0);
	}

	uint64_t bit, bit0xff;
	int	i, j, k, n;
	int	**res, *col, p;

	memset(&bit0xff, 0xff, 8);
	res = malloc((1 << numsSize) * sizeof(*res));
	col = malloc((1 << numsSize) * sizeof(*col));
	p = 0;
	for (bit = 0; bit < ((uint64_t)1 << numsSize); bit++) {
		n = 0;
		for (i = 0; i < numsSize; i++) {
			if (bit & ((uint64_t)1 << i))
				n++;
		}
		if (!n) {
			res[p] = 0;
			col[p] = 0;
			p++;
			continue;
		}
		res[p] = malloc(n * sizeof(int));

		j = 0;
		for (i = 0; i < numsSize; i++) {
			if (bit & ((uint64_t)1 << i))
				res[p][j++] = nums[i];
		}
		qsort(res[p], n, sizeof(int), intcmp);
		col[p] = n;
		p++;
	}

	*columnSizes = col;
	*returnSize = p;
	return(res);
}

int main(void)
{
	int **res, *col, n;
	int x[] = { 1, 2, 3};
	res = subsets(x, 3, &col, &n);
	return(0);
}
