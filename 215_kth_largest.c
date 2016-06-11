static inline void swap(int *nums, int i, int j)
{
	int t = nums[i];
	nums[i] = nums[j];
	nums[j] = t;
}

int findKthLargest(int *nums, int numsSize, int k)
{
	int left, right, i, last, t;

	left = 0;
	right = numsSize - 1;
	while (1) {
		last = left;
		for (i = left + 1; i <= right; i++) {
			if (nums[i] >= nums[left])
				continue;
			swap(nums, ++last, i);
		}
		swap(nums, left, last);
		t = numsSize - last;
		if (t == k)
			return(nums[last]);
		else if (t > k)
			left = last + 1;
		else
			right = last - 1;
	}
}
int main(void)
{
	int a[] = { 3, 2, 1, 5, 6, 4, };
	findKthLargest(a, sizeof(a) / sizeof(a[0]), 2);
}
