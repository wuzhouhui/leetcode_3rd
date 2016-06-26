int findDuplicate(int *nums, int numsSize)
{
	int left, right, i, mid;
	int le, gt;

	left = 1;
	right = numsSize - 1;
	while (1) {
		mid = (left + right) / 2;
		le = gt = 0;
		for (i = 0; i < numsSize; i++)
			if (nums[i] >= left && nums[i] <= mid)
				le++;
			else if (nums[i] > mid && nums[i] <= right)
				gt++;
		if (le > (mid - left + 1))
			right = mid;
		else
			left = mid + 1;
		if (left == right)
			return(left);
	}
	return(0);
}
#include <stdio.h>
main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 1};
	printf("%d\n", findDuplicate(a, sizeof(a) / sizeof(a[0])));
}
