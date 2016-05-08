int removeDuplicates(int *nums, int numsSize)
{
	int	i, j, c;

	for (j = -1, i = 0; i < numsSize; i++) {
		if (i == 0) {
			nums[++j] = nums[i];
			c = 1;
			continue;
		}
		if (nums[i] == nums[i - 1]) {
			if (c < 2) {
				nums[++j] = nums[i];
				c++;
			}
			continue;
		}
		nums[++j] = nums[i];
		c = 1;
	}
	return(++j);
}

int main(void)
{
}
