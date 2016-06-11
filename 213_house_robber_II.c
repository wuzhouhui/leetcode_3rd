static inline int max(int a, int b)
{
	return(a > b ? a : b);
}

static int do_rob(int *nums, int n)
{
	int	sum[n];
	int	i, t;

	if (n == 1)
		return(nums[0]);
	if (n == 2)
		return(max(nums[0], nums[1]));
	sum[0] = nums[0];
	sum[1] = max(nums[0], nums[1]);
	for (i = 2; i < n; i++) {
		t = nums[i] + sum[i - 2];
		if (t > sum[i - 1])
			sum[i] = t;
		else
			sum[i] = sum[i - 1];
	}
	return(sum[n - 1]);
}

int rob(int *nums, int numSize)
{
	if (numSize == 0)
		return(0);
	if (numSize == 1)
		return(nums[0]);
	if (numSize == 2)
		return(max(nums[0], nums[1]));

	int	money[numSize];
	return(max(do_rob(nums, numSize - 1), do_rob(nums + 1, numSize - 1)));
}

int main(void)
{
}
