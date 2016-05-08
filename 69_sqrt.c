#include <limits.h>

int mySqrt(int x)
{
	long down, up, mid, t;

	down = 0;
	up = INT_MAX;
	while (down + 1 != up) {
		mid = (down + up) / 2;
		t = mid * mid;
		if (t == x)
			return(mid);
		else if (t < x)
			down = mid;
		else
			up = mid;
	}
	return(down);
}

int main(void)
{
}
