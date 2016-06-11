/*
 * a little slow.
 */
#include <string.h>

#ifndef bool
#define bool int
#endif

bool canFinish(int numCourses, int **prerequistites, int prerequistitesRowSize,
		int prerequistitesColSize)
{
	int in[numCourses], left;
	int i, j;

	memset(in, 0, sizeof(in));
	for (i = 0; i < prerequistitesRowSize; i++)
		in[prerequistites[i][0]]++;
	left = numCourses;
	while (left > 0) {
		for (i = 0; i < numCourses; i++)
			if (in[i] == 0)
				break;
		if (i >= numCourses)
			return(0);
		left--;
		in[i]--;
		for (j = 0; j < prerequistitesRowSize; j++) {
			if (prerequistites[j][1] != i)
				continue;
			in[prerequistites[j][0]]--;
		}
	}
	return(1);
}

int main(void)
{
	int a[] = {1, 0, };
	int *b[] = { a };
	canFinish(2, b, 1, 2);
}
