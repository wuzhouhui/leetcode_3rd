#include <stdlib.h>

struct valind {
	int val, ind;
};

#ifndef bool
#define bool int
#endif

static int cmp(const void *a, const void *b)
{
	const struct valind *p1 = (const struct valind *)a;
	const struct valind *p2 = (const struct valind *)b;
	if (p1->val != p2->val)
		return(p1->val - p2->val);
	else
		return(p1->ind - p2->ind);
}

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
	if (numsSize <= 1)
		return(0);
	int i;
	struct valind *valind = malloc(numsSize * sizeof(*valind));
	for (i = 0; i < numsSize; i++) {
		valind[i].val = nums[i];
		valind[i].ind = i;
	}
	qsort(valind, numsSize, sizeof(*valind), cmp);
	for (i = 1; i < numsSize; i++)
		if (valind[i].val != valind[i - 1].val ||
				valind[i].ind - valind[i - 1].ind > k)
			continue;
		else {
			free(valind);
			return(1);
		}
	free(valind);
	return(0);
}

int main(void)
{
	int a[] = { 99, 99, };
	containsNearbyDuplicate(a, 2, 2);
}
