#include <string.h>

int numSquares(int n)
{
	if (n <= 0)
		return(0);
	unsigned int square[n + 1];
	int i, j, t, t1;

	memset(square, 0xff, sizeof(square));
	for (i = 1; (t = i * i) <= n; i++)
		square[t] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; (t = i + j * j) <=n; j++) {
			t1 = square[i] + 1;
			if (t1 < square[t])
				square[t] = t1;
		}
	}
	return(square[n]);
}
main(){}
