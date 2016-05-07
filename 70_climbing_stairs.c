int climbStairs(int n)
{
	if (n < 1)
		return(0);
	int	ways[n], i;

	for (i = 0; i < n; i++) {
		if (i == 0) {
			ways[0] = 1;
			continue;
		}
		if (i == 1) {
			ways[1] = 2;
			continue;
		}
		ways[i] = ways[i - 1] + ways[i - 2];
	}
	return(ways[n - 1]);
}

int main(void)
{
}
