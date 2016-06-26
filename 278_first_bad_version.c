bool isBadVersion(int version);

int firstBadVersion(int n)
{
	int l, mid;

	l = 0;
	while (l + 1 != n) {
		mid = l + (n - l) / 2; /* avoid overflow */
		if (isBadVersion(mid) == 0)
			l = mid;
		else
			n = mid;
	}
	return(n);
}
