#include <stdlib.h>

int *countBits(int num, int *returnSize)
{
	*returnSize = num + 1;
	int *res = calloc(*returnSize, sizeof(*res));
	int i;
	for (i = 1; i <= num; i++)
		res[i] = res[i >> 1] + (i & 1);
	return(res);
}
main(){}
