int rob(int *nums, int numsSize)
{
	if (numsSize <= 0)
		return(0);
	if (numsSize <= 1)
		return(nums[0]);
	int money[numsSize];
	int i, t;
	money[0] = nums[0];
	money[1] = nums[0] > nums[1] ? nums[0] : nums[1];
	for (i = 2; i < numsSize; i++) {
		t = nums[i] + money[i - 2];
		money[i] = t > money[i - 1] ? t : money[i - 1];
	}
	return(money[numsSize - 1]);
}

main(){}
