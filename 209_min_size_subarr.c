int minSubArrayLen(int s, int *nums, int numsSize)
{
	if (numsSize <= 0)
		return(0);

	int t, min, sum, left, right;
	min = left = right = 0;
	sum = nums[0];
	while (right < numsSize) {
		while (sum < s) {
			if (right >= numsSize - 1)
				return(min);
			sum += nums[++right];
		}
		if (left == right)
			return(1);
		while (sum >= s)
			sum -= nums[left++];
		t = right - left + 2;
		if (min == 0 || t < min)
			min = t;
	}
	return(min);
}

main(){}
