int firstMissingPositive(int *nums, int numsSize)
{
	int	i, t;

	if (numsSize < 1)
		return(1);

	i = 0;
	while (i < numsSize) {
		if (nums[i] != i + 1 && nums[i] >= 1 && nums[i] <= numsSize
				&& nums[nums[i] - 1] != nums[i]) {
			t = nums[i];
			nums[i] = nums[t - 1];
			nums[t - 1] = t;
		} else
			i++;
	}
	for (i = 0; i < numsSize; i++) {
		if (nums[i] != i + 1)
			return(i + 1);
	}
	return(numsSize + 1);
}

#include <stdio.h>

int main(void)
{
	int	a[] = { 1, 1 };
	printf("%d\n", firstMissingPositive(a, sizeof(a) / sizeof(a[0])));
	return(0);
}
