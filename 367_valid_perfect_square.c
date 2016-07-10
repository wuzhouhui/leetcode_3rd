#ifndef bool
#define bool int
#endif

bool isPerfectSquare(int num)
{
	unsigned long long t;
	int	x = 0;
	while ((t = x * x) < num)
		x++;
	return(t == num);
}

bool isPerfectSquare2(int num)
{
	if (num <= 0)
		return(0);
	long int l = 0, r = num / 2 + 1, m, t;
	while (l <= r) {
		m = (r - l) / 2 + l;
		t = m * m;
		if (t == num)
			return(1);
		else if (t < num)
			l = m + 1;
		else
			r = m - 1;
	}
	return(0);
}

main(){}
