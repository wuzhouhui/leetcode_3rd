#include <stdint.h>

static int bit[] = {
	0, 8, 4, 12,
	2, 10, 6, 14,
	1, 9, 5, 13,
	3, 11, 7, 15,
};

uint32_t reverseBits(uint32_t n)
{
	uint32_t r = 0;
	r = bit[n & 15]; n >>= 4;
	r = (r << 4) | bit[n & 15]; n >>= 4;
	r = (r << 4) | bit[n & 15]; n >>= 4;
	r = (r << 4) | bit[n & 15]; n >>= 4;
	r = (r << 4) | bit[n & 15]; n >>= 4;
	r = (r << 4) | bit[n & 15]; n >>= 4;
	r = (r << 4) | bit[n & 15]; n >>= 4;
	r = (r << 4) | bit[n & 15]; n >>= 4;
	return(r);
}

int main(void)
{
}
