int lengthOfLIS(int *nums, int numsSize)
{
	if (numsSize < 2)
		return(numsSize);
	int len[numsSize];
	int i, j, max, t;
	for (i = 0; i < numsSize; i++)
		len[i] = 1;
	max = 1;
	for (i = 1; i < numsSize; i++)
		for (j = 0; j < i; j++) {
			if (nums[j] < nums[i])
				t = len[j] + 1;
			else
				continue;
			if (t > len[i])
				len[i] = t;
			if (t > max)
				max = t;
		}
	return(max);
}
main(){}
