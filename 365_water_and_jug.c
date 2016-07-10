#ifndef bool
#define bool int
#endif

static int gcd(int x, int y)
{
	return(y == 0 ? x : gcd(y, x % y));
}

bool canMeasureWater(int x, int y, int z)
{
	return(x + y == z || (z < x + y) && z % gcd(x, y) == 0);
}
main(){}
