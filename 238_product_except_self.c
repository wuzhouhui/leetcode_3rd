#include <stdlib.h>

int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
	int *res = malloc(numsSize * sizeof(*res));
	int	i, right;

	res[0] = 1;
	for (i = 1; i < numsSize; i++)
		res[i] = res[i - 1] * nums[i - 1];
	right = 1;
	for (i = numsSize - 1; i >= 0; i--) {
		res[i] *= right;
		right *= nums[i];
	}
	*returnSize = numsSize;
	return(res);
}
main(){}
