int singleNumber(int *nums, int numsSize)
{
	int one, two, comm, i;
	one = nums[0];
	comm = two = 0;
	for (i = 1; i < numsSize; i++) {
		two |= one & nums[i];
		one ^= nums[i];
		comm = one & two;
		one &= ~comm;
		two &= ~comm;
	}
	return(one);
}

int main(void)
{
}
