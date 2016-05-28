int maxProfit(int *prices, int pricesSize)
{
	int	i, j, m, t, max;

	m = prices[pricesSize - 1];
	max = 0;
	for (i = pricesSize - 2; i >= 0; i--) {
		t = m;
		if (prices[i] > m)
			m = prices[i];
		prices[i] = t - prices[i];
		if (prices[i] > max)
			max = prices[i];
	}
	return(max);
}

#include <stdio.h>

int main(void)
{
	int a[] = { 1, 3, 1, };
	printf("%d\n", maxProfit(a, sizeof(a) / sizeof(a[0])));
	return(0);
}
