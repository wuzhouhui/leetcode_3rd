#include <stdlib.h>

#ifndef bool
#define bool
#endif

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

bool containsDuplicate(int *nums, int numsSize)
{
	int	i;

	qsort(nums, numsSize, sizeof(nums[0]), intcmp);
	for (i = 1; i < numsSize; i++)
		if (nums[i] == nums[i - 1])
			return(1);
	return(0);
}

int main(void)
{
}
