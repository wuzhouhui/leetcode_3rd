int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize)
{
	if (gasSize <= 0)
		return(-1);
	int left, total, i, j, ret;
	ret = left = total = 0;
	for (i = 0; i < gasSize; i++) {
		left += gas[i] - cost[i];
		total += left;
		if (left < 0) {
			left = 0;
			ret = i + 1;
		}
	}
	return(total < 0 ? -1 : ret);
}

int main(void)
{
}
