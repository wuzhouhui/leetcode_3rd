int hIndex(int *citations, int citationsSize)
{
	int left, right, mid;
	left = -1;
	right = citationsSize;
	while (left + 1 != right) {
		mid = (left + right) / 2;
		if (citations[mid] < citationsSize - mid)
			left = mid;
		else
			right = mid;
	}
	if (right == citationsSize || citations[right] < citationsSize - right)
		return(0);
	else
		return(citationsSize - right);
}
main(){}
