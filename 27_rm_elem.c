int removeElement(int *nums, int numsSize, int val)
{
	int	i, j;

	for (j = -1, i = 0; i < numsSize; i++) {
		if (nums[i] == val)
			continue;
		else
			nums[++j] = nums[i];
	}
	return(++j);
}

int main(void)
{
}
