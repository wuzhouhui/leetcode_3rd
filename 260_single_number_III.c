#include <stdlib.h>

int *singleNumber(int *nums, int numsSize, int *returnSize)
{
	int *res = calloc(2, sizeof(int));
	unsigned int i, t;
	for (t = i = 0; i < numsSize; i++)
		t ^= nums[i];
	t -=t & (t - 1);
	for (i = 0; i < numsSize; i++) {
		if (nums[i] & t)
			res[0] ^= nums[i];
		else
			res[1] ^= nums[i];
	}
	*returnSize = 2;
	return(res);
}
main(){}
