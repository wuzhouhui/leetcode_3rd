/*
 * a little slow.
 */

#include <string.h>
#include <stdlib.h>

int *findOrder(int numCourses, int **prerequistites, int prerequistitesRowSize,
		int prerequistitesColSize, int *returnSize)
{
	int in[numCourses], left;
	int i, j, p = 0;
	int *res = malloc(numCourses * sizeof(*res));

	memset(in, 0, sizeof(in));
	for (i = 0; i < prerequistitesRowSize; i++)
		in[prerequistites[i][0]]++;
	left = numCourses;
	while (left > 0) {
		for (i = 0; i < numCourses; i++)
			if (in[i] == 0)
				break;
		if (i >= numCourses) {
			free(res);
			*returnSize = 0;
			return(NULL);
		}
		left--;
		in[i]--;
		res[p++] = i;
		for (j = 0; j < prerequistitesRowSize; j++) {
			if (prerequistites[j][1] != i)
				continue;
			in[prerequistites[j][0]]--;
		}
	}
	*returnSize = p;
	return(res);
}

int main(void)
{
}
