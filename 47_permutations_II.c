/*
 * Too slow, but accepted.
 */

#include <stdlib.h>
#include <string.h>

static int **res, p, maxp;

static void addans(const int *ans, int len)
{
	int	i;

	for (i = 0; i < p; i++) {
		if (!memcmp(res[i], ans, len * sizeof(*ans)))
			return;
	}
	if (!res) {
		maxp = 8;
		res = malloc(maxp * sizeof(*res));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p] = malloc(len * sizeof(*ans));
	memcpy(res[p], ans, len * sizeof(*ans));
	p++;
}

static void do_permute(const int *nums, int len, int level, int *buf,
		char *occupy)
{
	if (level >= len) {
		addans(buf, len);
		return;
	}

	int	i;

	for (i = 0; i < len; i++) {
		if (occupy[i])
			continue;
		occupy[i] = 1;
		buf[level] = nums[i];
		do_permute(nums, len, level + 1, buf, occupy);
		occupy[i] = 0;
	}
}


int **permuteUnique(int *nums, int numsSize, int *returnSize)
{
	char	occupy[numsSize];
	int	buf[numsSize];

	res = 0;
	p = 0;
	memset(occupy, 0, sizeof(occupy));
	do_permute(nums, numsSize, 0, buf, occupy);
	*returnSize = p;
	return(res);
}

void main(void)
{
}
