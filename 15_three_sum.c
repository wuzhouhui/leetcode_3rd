#include <stdlib.h>
#include <string.h>

static int **res, p, maxp;

static void addans(int a, int b, int c)
{
	int	*ans;

	ans = calloc(3, sizeof(*ans));
	ans[0] = a;
	ans[1] = b;
	ans[2] = c;
	for (a = 0; a < p; a++) {
		if (!memcmp(ans, res[a], 3 * sizeof(*ans))) {
			free(ans);
			return;
		}
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
	res[p++] = ans;
}

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

int **threeSum(int *nums, int numsSize, int *returnSize)
{
	int	l, i, r, t;

	res = NULL;
	p = 0;
	if (numsSize < 3) {
		*returnSize = 0;
		return(NULL);
	}
	qsort(nums, numsSize, sizeof(nums[0]), intcmp);
	for (i = 1; i < numsSize - 1; i++) {
		l = 0, r = numsSize - 1;
		while (l < i && i < r) {
			t = nums[l] + nums[i] + nums[r];
			if (t == 0) {
				addans(nums[l], nums[i], nums[r]);
				l++, r--;
			} else if (t < 0)
				l++;
			else
				r--;
		}
	}
	*returnSize = p;
	return(res);
}

void main(void)
{
}
