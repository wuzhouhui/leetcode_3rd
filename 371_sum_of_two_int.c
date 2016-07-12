int getSum(int a, int b)
{
	int res = 0, c, i, bit;

	c = 0;
	for (i = 0; i < sizeof(int) * 8; i++) {
		bit = (a & (1 << i)) ? 1 : 0;
		bit = (bit << 1) | ((b & (1 << i)) ? 1 : 0);
		bit = (bit << 1) | c;
		c = 0;
		switch (bit) {
		case 0:
			break;
		case 1:
		case 2:
		case 4:
			res |= (1 << i);
			break;
		case 3:
		case 5:
		case 6:
			c = 1;
			break;
		default:
			c = 1;
			res |= (1 << i);
			break;
		}
	}
	return(res);
}
int main(void)
{
}
