static double dopow(double x, long long int n)
{
	if (n == 0)
		return(1.0);
	if (n == 1)
		return(x);
	if (n % 2)
		return(x * dopow(x, n - 1));
	double t = dopow(x, n / 2);
	return(t * t);
}

double myPow(double x, int n)
{
	long long int t = n;
	if (t < 0)
		t = -t;
	if (n >= 0)
		return(dopow(x, t));
	else
		return(1 / dopow(x, t));
}

int main(void)
{
}
