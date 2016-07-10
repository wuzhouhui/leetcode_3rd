int countNumbersWithUniqueDigits(int n)
{
	if (n < 0 || n >= 11)
		return(0);
	if (n == 0)
		return(1);

	int dp[n + 1];
	int i, t, k;

	dp[0] = 1;
	dp[1] = 10;
	for (i = 2; i <= n; i++) {
		t = 9;
		for (k = 9; k >= 11 - i; k--)
			t *= k;
		dp[i] = t + dp[i - 1];
	}
	return(dp[n]);
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", countNumbersWithUniqueDigits(2));
	printf("%d\n", countNumbersWithUniqueDigits(3));
	return(0);
}
