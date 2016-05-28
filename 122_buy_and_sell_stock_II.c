int maxProfit(int *prices, int priceSize)
{
	int i, buy, profit;
	profit = i = 0;
	while (i < priceSize) {
		buy = prices[i++];
		while (i < priceSize && prices[i] >= prices[i - 1])
			i++;
		profit += prices[i - 1] - buy;
	}
	return(profit);
}

int main(void)
{
	int a[] = { 1,2,1,2,};
	maxProfit(a, sizeof(a) / sizeof(a[0]));
	return(0);
}
