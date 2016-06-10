#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int cmpfun(const void *a, const void *b)
{
	static char buf1[32], buf2[32];
	int	i;
	sprintf(buf1, "%d%d", *(int *)a, *(int *)b);
	sprintf(buf2, "%d%d", *(int *)b, *(int *)a);
	for (i = 0; buf1[i]; i++)
		if (buf1[i] == buf2[i])
			continue;
		else
			return(buf2[i] - buf1[i]);
	return(0);
}

static int totlen(const int *nums, int len)
{
	int i, n, r;
	for (r = i = 0; i < len; i++) {
		n = nums[i];
		do {
			r++;
			n /= 10;
		} while (n);
	}
	return(r);
}

char *largestNumber(int *nums, int numsSize)
{
	if (numsSize <= 0)
		return(strdup("0"));
	int len, i, p;
	char *res;
	qsort(nums, numsSize, sizeof(nums[0]), cmpfun);
	len = totlen(nums, numsSize);
	res = malloc((len + 1) * sizeof(*res));
	for (p = i = 0; i < numsSize; i++)
		p += sprintf(res + p, "%d", nums[i]);
	if (res[0] == '0')
		res[1] = 0;
	return(res);
}

int main(void)
{
	int a[] = { 3, 30, 34, 5, 9, };
	printf("%s\n", largestNumber(a, sizeof(a) / sizeof(a[0])));
	return(0);
}
