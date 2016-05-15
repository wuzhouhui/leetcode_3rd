#include <stdlib.h>
#include <string.h>

void merge(int *nums1, int m, int *nums2, int n)
{
	int	*t, i, j, k;

	if (!n)
		return;
	if (!m)
		memcpy(nums1, nums2, n * sizeof(nums2[0]));
	t = malloc((m + n) * sizeof(nums1[0]));
	i = j = k = 0;
	while (i < m && j < n) {
		if (nums1[i] < nums2[j]) {
			t[k++] = nums1[i];
			i++;
		} else {
			t[k++] = nums2[j];
			j++;
		}
	}
	if (i < m)
		memcpy(t + k, nums1 + i, (m - i) * sizeof(nums1[0]));
	if (j < n)
		memcpy(t + k, nums2 + j, (n - j) * sizeof(nums2[0]));
	memcpy(nums1, t, (m + n) * sizeof(nums1[0]));
	free(t);
	return;
}

int main(void)
{
}
