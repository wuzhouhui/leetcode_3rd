#include <stdlib.h>

int **generate(int numRows, int **columnSizes)
{
	if (numRows <= 0) {
		*columnSizes = 0;
		return(0);
	}
	int	i, j, **res;

	res = malloc(numRows * sizeof(*res));
	*columnSizes = malloc(numRows * sizeof(**columnSizes));
	for (i = 0; i < numRows; i++) {
		res[i] = malloc((i + 1) * sizeof(res[0][0]));
		(*columnSizes)[i] = i + 1;
		for (j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				res[i][j] = 1;
			else
				res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		}
	}
	return(res);
}

int main(void)
{
}
