#ifndef bool
#define bool int
#endif

bool isUgly(int num)
{
	if (num <= 0)
		return(0);
	while (num != 1) {
		if (num % 2 == 0)
			num /= 2;
		else if (num % 3 == 0)
			num /= 3;
		else if (num % 5 == 0)
			num /= 5;
		else
			return(0);
	}
	return(1);
}
main(){}
