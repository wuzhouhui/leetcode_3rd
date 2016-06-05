int findMin(int *nums, int numsSize)
{
	if (numsSize <= 0)
		return(0);
	int l = 0, r = numsSize - 1;
	numsSize = 0;
	while (nums[l] > nums[r]) {
		if (l + 1 == r)
			return(nums[r]);
		numsSize = (l + r) / 2;
		if (nums[numsSize] > nums[l])
			l = numsSize;
		else
			r = numsSize;
	}
	return(nums[numsSize]);
}

int main(void)
{
}
