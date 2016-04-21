#include <limits.h>
#include <ctype.h>

int myAtoi(char *str)
{
	long long int t, res;
	int	sign;

	while (*str && isblank(*str))
		str++;
	if (*str == 0)
		return(0);
	res = 0;
	sign = 1;
	if (!isdigit(*str)) {
		if (*str == '+')
			str++;
		else if (*str == '-') {
			sign = -1;
			str++;
		} else
			return(0);
	}
	while (*str && isdigit(*str)) {
		res = res * 10 + *str - '0';
		t = sign * res;
		if (t < INT_MIN)
			return(INT_MIN);
		if (t > INT_MAX)
			return(INT_MAX);
		str++;
	}
	return((int)(res * sign));
}

int main(void)
{
}
