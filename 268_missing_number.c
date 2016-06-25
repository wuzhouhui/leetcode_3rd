static void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int missingNumber(int *nums, int numsSize)
{
	int i;

	if (nums <= 0)
		return(0);
	for (i = 0; i < numsSize; i++) {
		while (nums[i] >= 1 && nums[i] != i + 1)
			swap(&nums[i], &nums[nums[i] - 1]);
	}
	for (i = 0; i < numsSize; i++)
		if (nums[i] != i + 1)
			return(i + 1);
	return(0);
}
main(){}
