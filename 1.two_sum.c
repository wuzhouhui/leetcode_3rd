#include <stdlib.h>

struct validx {
	int	val;
	int	idx;
};

static int cmp(const void *a, const void *b)
{
	return(((struct validx *)a)->val - ((struct validx *)b)->val);
}

int *twoSum(int *nums, int numsSize, int target)
{
	int	left, right, t, *res;
	struct validx n[numsSize];

	for (left = 0; left < numsSize; left++) {
		n[left].val = nums[left];
		n[left].idx = left;
	}

	qsort(n, numsSize, sizeof(n[0]), cmp);
	left = 0;
	right = numsSize - 1;
	while (1) {
		t = n[left].val + n[right].val;
		if (t == target)
			break;
		else if (t < target)
			left++;
		else
			right--;
	}
	res = malloc(sizeof(int) << 1);
	res[0] = n[left].idx;
	res[1] = n[right].idx;
	return(res);
}

int main(void)
{
}
