#ifndef bool
#define bool int
#endif

bool search(int *nums, int numsSize, int target)
{
	int	left, right, mid;

	if (!numsSize)
		return(0);
	if (numsSize == 1)
		return(nums[0] == target);
	left = 0;
	right = numsSize - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (nums[mid] == target)
			return(1);
		if (nums[left] < nums[right]) {
			if (nums[mid] < nums[right]) {
				if (target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			} else {
				if (target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
		} else if (nums[left] > nums[right]) {
			if (nums[mid] >= nums[left]) {
				if (target < nums[mid])
					if (target >= nums[left])
						right = mid - 1;
					else
						left = mid + 1;
				else
					left = mid + 1;
			} else {
				if (target > nums[mid] && target <= nums[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
		} else {
			left++;
		}
	}
	return(0);
}

int main(void)
{
}
