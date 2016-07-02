#include <limits.h>

#ifndef bool
#define bool int
#endif

bool increasingTriplet(int *nums, int numsSize)
{
	if (numsSize < 3)
		return(0);
	int a1, a2, i;

	a1 = a2 = INT_MAX;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] < a1)
			a1 = nums[i];
		else if (nums[i] > a1 && nums[i] < a2)
			a2 = nums[i];
		else if (nums[i] > a2)
			return(1);
	}
	return(0);
}
main(){}
