#include <stdlib.h>

static inline int min(int a, int b)
{
	return(a < b ? a : b);
}

int nthUglyNumber(int n)
{
	if (n <= 0)
		return(0);
	if (n == 1)
		return(1);
	int nums[n];
	int i, t2, t3, t5, i2, i3, i5;

	nums[0] = 1;
	i2 = i3 = i5 = 0;
	for (i = 1; i < n; i++) {
		t2 = nums[i2] * 2;
		t3 = nums[i3] * 3;
		t5 = nums[i5] * 5;
		nums[i] = min(t2, min(t3, t5));
		if (nums[i] == t2)
			i2++;
		if (nums[i] == t3)
			i3++;
		if (nums[i] == t5)
			i5++;
	}
	return(nums[n - 1]);
}
main(){}
