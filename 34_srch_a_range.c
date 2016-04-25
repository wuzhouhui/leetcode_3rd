#include <stdlib.h>

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	int	*res, left, right, mid;

	res = malloc(sizeof(int) << 1);
	*returnSize = 2;

	if (numsSize == 0) {
		res[0] = res[1] = -1;
		return(res);
	}
	if (numsSize == 1) {
		res[0] = res[1] = (nums[0] == target ? 0 : -1);
		return(res);
	}

	left = -1;
	right = numsSize;
	while (left + 1 != right) {
		mid = (left + right) / 2;
		if (nums[mid] < target)
			left = mid;
		else
			right = mid;
	}
	if (right >= numsSize || nums[right] != target) {
		res[0] = res[1] = -1;
		return(res);
	} else {
		res[0] = right;
	}

	left = -1;
	right = numsSize;
	while (left + 1 != right) {
		mid = (left + right) / 2;
		if (nums[mid] > target)
			right = mid;
		else
			left = mid;
	}
	res[1] = left;
	return(res);
}

int main(void)
{
}
