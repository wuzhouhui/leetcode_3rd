static inline max(int a, int b)
{
	return(a > b ? a : b);
}

static inline min(int a, int b)
{
	return(a < b ? a : b);
}

int maxProduct(int *nums, int numsSize)
{
	if (numsSize <= 0)
		return(0);
	int glomax, curmax, curmin;
	int i, t;
	glomax = curmax = curmin = nums[0];
	for (i = 1; i < numsSize; i++) {
		t = curmax;
		curmax = max(nums[i], max(curmax * nums[i], curmin * nums[i]));
		curmin = min(nums[i], min(curmin * nums[i], t * nums[i]));
		glomax = max(curmax, glomax);
	}
	return(glomax);
}

int main(void)
{
	return(0);
}
