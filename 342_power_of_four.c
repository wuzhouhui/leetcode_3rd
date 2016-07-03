#ifndef bool
#define bool int
#endif

bool isPowerOfFour(int num)
{
	return(num > 0 && !(num & (num - 1)) && (num & (int)0x55555555));
}
main(){}
