static int inline max(int a, int b)
{
	return(a > b ? a : b);
}

int integerBreak(int n)
{
	if (n <= 3)
		return(n - 1);
	static int dp[59];
	int i, j;
	for (i = 1; i <= n; i++)
		dp[i] = 1;
	for (i = 1; i < n; i++) {
		for (j = i; (i + j) <= n; j++)
			dp[i + j] = max(dp[i + j],
					max(dp[i], i) * max(dp[j], j));
	}
	return(dp[n]);
}
main(){}
