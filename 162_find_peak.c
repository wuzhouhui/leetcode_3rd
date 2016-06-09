int findPeakElement(int *nums, int numsSize)
{
	int left = -1, right = numsSize, mid;
	int l, r;
	while (1) {
		mid = (left + right) / 2;
		l = mid - 1;
		r = mid + 1;
		if (l != -1 && r != numsSize) {
			if (nums[l] < nums[mid] && nums[mid] < nums[r])
				left = mid;
			else if (nums[l] > nums[mid] && nums[mid] > nums[r])
				right = mid;
			else if (nums[mid] > nums[l] && nums[mid] > nums[r])
				return(mid);
			else
				left = mid;
		} else if (l == -1 && r == numsSize) {
			return(mid);
		} else if (l == -1) {
			if (nums[mid] > nums[r])
				return(mid);
			else
				left = mid;
		} else {
			if (nums[mid] > nums[l])
				return(mid);
			else
				right = mid;
		}
	}
	return(0);
}

int main(void)
{
	int a[] = {1, 2, 3, 1, };
	findPeakElement(a, 4);
	return(0);
}
