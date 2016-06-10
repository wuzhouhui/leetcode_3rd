#define BIT(i, j) (i & (1 << j))

int rangeBitwiseAnd(int m, int n)
{
	int	res, diff, i;

	diff = n - m;
	res = 0;
	for (i = 0; i < 32; i++) {
		if (BIT(m, i) == 0 || BIT(m, i) == 0)
			continue;
		if (diff >= ((1 << i) - (m & ((1 << i) - 1))))
			continue;
		res |= 1 << i;
	}
	return(res);
}

main(){}
