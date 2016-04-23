#include <stdlib.h>
#include <limits.h>

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

int threeSumClosest(int *nums, int numsSize, int target)
{
	long int min, diff;
	int	res, t, i, l, r;

	min = INT_MAX;
	qsort(nums, numsSize, sizeof(nums[0]), intcmp);
	for (i = 1; i < numsSize - 1; i++) {
		l = 0, r = numsSize - 1;
		while (l < i && i < r) {
			t = nums[l] + nums[i] + nums[r];
			diff = t - target;
			if (diff == 0)
				return(t);

			if (labs(diff) < labs(min)) {
				min = diff;
				res = t;
				if (diff < 0)
					l++;
				else
					r--;
			} else if (diff < 0)
				l++;
			else
				r--;
		}
	}
	return(res);
}

void main(void)
{
}
