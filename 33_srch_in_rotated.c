int search(int *nums, int numsSize, int target)
{
	int	left, right, mid;

	if (numsSize == 0)
		return(-1);
	if (numsSize == 1)
		return(nums[0] == target ? 0 : -1);
	left = 0;
	right = numsSize - 1;
	while (left <= right) {
		mid = (left + right) >> 1;
		if (nums[mid] == target)
			return(mid);
		if (nums[left] <= nums[right]) {
			if (target < nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
			continue;
		}
		if (nums[mid] > nums[right]) {
			if (target < nums[mid]) {
				if (target > nums[right])
					right = mid - 1;
				else
					left = mid + 1;
			} else
				left = mid + 1;
		} else {
			if (target >= nums[left])
				right = mid - 1;
			else if (target < nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
	}
	return(-1);
}

void main(void)
{
}
