#include <stdlib.h>
#include <string.h>

int *getRow(int rowIndex, int *returnSize)
{
	if (rowIndex < 0) {
		*returnSize = 0;
		return(0);
	}

	int *res, *tmp;
	int i, j;

	res = malloc((rowIndex + 1) * sizeof(*res));
	tmp = malloc((rowIndex + 1) * sizeof(*tmp));
	for (i = 0; i <= rowIndex; i++) {
		memcpy(tmp, res, (rowIndex + 1) * sizeof(*res));
		for (j = 0; j <= i; j++)
			if (j == 0 || j == i)
				res[j] = 1;
			else
				res[j] = tmp[j - 1] + tmp[j];
	}
	free(tmp);
	*returnSize = rowIndex + 1;
	return(res);
}

int main(void)
{
}
