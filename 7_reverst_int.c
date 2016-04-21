#include <limits.h>

int reverse(int x)
{
	long long res;
	long long llx = x;
	int	sign;

	if (llx < 0) {
		sign = -1;
		llx = -llx;
	} else
		sign = 1;

	res = 0;
	while (llx) {
		res = res * 10 + llx % 10;
		llx /= 10;
	}
	res *= sign;
	if (res < INT_MIN || res > INT_MAX)
		res = 0;
	return((int)res);
}

int main(void)
{
}
