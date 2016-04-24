int removeDuplicates(int *nums, int numsSize)
{
	int	i, j, prev;

	for (j = -1, i = 0; i < numsSize; i++) {
		if (j == -1 || nums[i] != prev) {
			nums[++j] = nums[i];
			prev = nums[i];
		} else
			continue;
	}
	return(++j);
}

int main(void)
{
}
