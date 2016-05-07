#include <stdlib.h>

static int *res, p, maxp;

static void addnum(int n)
{
	if (!res) {
		maxp = 8;
		p = 0;
		res = malloc(maxp * sizeof(*res));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p++] = n;
}

static void revert(int *nums, int len)
{
	int	i, t;
	i = 0;
	len--;
	while (i < len) {
		t = nums[i];
		nums[i] = nums[len];
		nums[len] = t;
		i++;
		len--;
	}
}

int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int	i, c;

	res = 0;
	revert(digits, digitsSize);
	c = 1;
	for (i = 0; i < digitsSize; i++) {
		digits[i] += c;
		c = 0;
		if (digits[i] > 9) {
			digits[i] -= 10;
			c = 1;
		}
		addnum(digits[i]);
	}
	if (c)
		addnum(c);
	revert(res, p);
	*returnSize = p;
	return(res);
}

int main(void)
{
}
