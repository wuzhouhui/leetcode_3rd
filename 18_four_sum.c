#include <stdlib.h>
#include <string.h>

static int **res, p, maxp;

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

static int addans(int a, int b, int c, int d)
{
	int	*t;

	t = calloc(4, sizeof(int));
	t[0] = a;
	t[1] = b;
	t[2] = c;
	t[3] = d;
	for (a = 0; a < p; a++)
		if (!memcmp(res[a], t, sizeof(int) << 2)) {
			free(t);
			return;
		}
	if (res == NULL) {
		maxp = 8;
		p = 0;
		res = malloc(maxp * sizeof(*res));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p++] = t;
}

static void do_sum(int first, const int *nums, int size, int tgt)
{
	int	l, m, r, t;

	for (m = 1; m < size - 1; m++) {
		l = 0;
		r = size - 1;
		while (l < m && m < r) {
			t = nums[l] + nums[m] + nums[r];
			if (t == tgt) {
				addans(first, nums[l], nums[m], nums[r]);
				l++, r--;
			} else if (t < tgt)
				l++;
			else
				r--;
		}
	}
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize)
{
	int	i;

	res = NULL;
	p = 0;
	qsort(nums, numsSize, sizeof(nums[0]), intcmp);
	for (i = 0; i < numsSize - 3; i++) {
		do_sum(nums[i], nums + i + 1, numsSize - i - 1,
				target - nums[i]);
	}
	*returnSize = p;
	return(res);
}

void main(void)
{

}
