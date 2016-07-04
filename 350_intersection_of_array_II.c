#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size,
		int *returnSize)
{
	int i1, i2, p = 0;
	int *res = malloc((nums1Size < nums2Size ? nums1Size : nums2Size)
			* sizeof(*res));
	qsort(nums1, nums1Size, sizeof(nums1[0]), cmp);
	qsort(nums2, nums2Size, sizeof(nums2[0]), cmp);
	i1 = i2 = 0;
	while (i1 < nums1Size && i2 < nums2Size) {
		if (nums1[i1] < nums2[i2]) {
			i1++;
		} else if (nums1[i1] > nums2[i2]) {
			i2++;
		} else {
			res[p++] = nums1[i1];
			i1++, i2++;
		}
	}
	res = realloc(res, p * sizeof(*res));
	*returnSize = p;
	return(res);
}
main(){}
