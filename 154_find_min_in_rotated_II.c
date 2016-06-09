int findMin(int *nums, int numsSize)
{
	if (numsSize <= 0)
		return(0);
	int l = 0, r = numsSize - 1, mid = l;
	while (l < r && nums[l] >= nums[r]) {
		if (l + 1 == r)
			return(nums[r]);
		mid = (l + r) / 2;
		if (nums[l] != nums[r]) {
			if (nums[mid] >= nums[l])
				l = mid;
			else
				r = mid;
		} else {
			if (nums[mid] == nums[l])
				l++;
			else if (nums[mid] > nums[l])
				l = mid;
			else
				r = mid;
		}
	}
	return(nums[l]);
}

int main(void)
{
}
