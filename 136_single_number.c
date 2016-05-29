int singleNumber(int *nums, int numsSize)
{
	if (numsSize <= 0)
		return(0);
	int i, n = nums[0];
	for (i = 1; i < numsSize; i++)
		n ^= nums[i];
	return(n);
}

int main(void)
{
}
