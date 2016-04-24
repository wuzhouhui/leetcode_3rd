#include <stdlib.h>
#include <limits.h>

int divide(int dividend, int divisor)
{
	long int x, y, res;
	int	n;

	x = labs(dividend);
	y = labs(divisor);
	if (y == 0)
		return(dividend >= 0 ? INT_MAX : INT_MIN);
	if (x == 0)
		return(0);
	if (y == 1) {
		if (divisor > 0)
			return(dividend);
		/* divisor == -1 */
		if (dividend >= 0)
			return(-dividend);
		else
			return(dividend == INT_MIN ? INT_MAX : -dividend);
	}

	res = 0;
	while (x >= y) {
		n = 0;
		while (y * (1L << n) <= x)
			n++;
		n--;
		res += 1L << n;
		x -= y * (1L << n);
	}
	if ((long)dividend * (long)divisor < 0) {
		res = -res;
		return(res < INT_MIN ? INT_MIN : res);
	}
	return(res > INT_MAX ? INT_MAX : res);
}

int main(void)
{
}
