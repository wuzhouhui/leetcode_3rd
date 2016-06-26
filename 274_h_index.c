#include <stdlib.h>
#include <string.h>

static int cmp(const void *a, const void *b)
{
	return(*(int *)b - *(int *)a);
}

int hIndex(int *citations, int citationsSize)
{
	int h, i;
	qsort(citations, citationsSize, sizeof(citations[0]), cmp);
	for (i = h = 0; i < citationsSize && citations[i] >= i + 1; i++)
		h++;
	return(h);
}

int hIndex2(int *citations, int citationsSize)
{
	int cita[citationsSize + 1];
	int total, i;

	memset(cita, 0, sizeof(cita));
	for (i = 0; i < citationsSize; i++)
		if (citations[i] > citationsSize)
			cita[citationsSize]++;
		else
			cita[citations[i]]++;
	total = 0;
	for (i = citationsSize; i >= 0; i--)
		if ((total += cita[i]) >= i)
			return(i);
	return(0);
}

main(){}
