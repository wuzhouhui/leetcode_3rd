int jump(int *nums, int numsSize)
{
	int	start, res, next, max, t;
	int	i;

	start = 0;
	res = 0;
	while (start < numsSize - 1) {
		max = 1;
		next = start + 1;
		for (i = 1; i <= nums[start]; i++) {
			if (start + i >= numsSize - 1)
				return(res + 1);
			t = i + nums[start + i];
			if (t > max) {
				max = t;
				next = start + i;
			}
		}
		start = next;
		res++;
	}
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	n[] = { 2, 3, 1, 1, 4, };
	printf("%d\n", jump(n, sizeof(n) / sizeof(n[0])));
	return(0);
}
