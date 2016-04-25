int searchInsert(int *nums, int numSize, int target)
{
	int	left, right, mid;

	left = -1;
	right = numSize;
	while (left + 1 != right) {
		mid = (left + right) / 2;
		if (nums[mid] < target)
			left = mid;
		else
			right = mid;
	}
	if (right < numSize && nums[right] == target)
		return(right);
	return(right);
}

int main(void)
{
}
