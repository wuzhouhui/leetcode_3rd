int maxSubArray(int *nums, int numsSize)
{
	if (numsSize < 1)
		return(0);

	int	max, curmax, i, t;

	max = curmax = nums[0];
	for (i = 1; i < numsSize; i++) {
		t = curmax + nums[i];
		curmax = t > nums[i] ? t : nums[i];
		if (curmax > max)
			max = curmax;
	}
	return(max);
}

int main(void)
{
}
