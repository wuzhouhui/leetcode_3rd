#include <string.h>

void moveZeroes(int *nums, int numsSize)
{
	int i, j;

	for (i = -1, j = 0; j < numsSize; j++)
		if (nums[j] == 0)
			continue;
		else
			nums[++i] = nums[j];
	i++;
	memset(&nums[i], 0, sizeof(nums[0]) * (numsSize - i));
}
main(){}
