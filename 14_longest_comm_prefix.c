#include <string.h>
#include <stdlib.h>

static int cmp(const void *a, const void *b)
{
	return(strcmp(*(char **)a, *(char **)b));
}

static int comm_len(const char *s1, const char *s2)
{
	int	i = 0;
	while (*s1 && *s2 && *s1 == *s2) {
		i++;
		s1++, s2++;
	}
	return(i);
}

char *longestCommonPrefix(char **strs, int strsSize)
{
	int	i, t, k, max;
	char	*res;

	if (strsSize == 0)
		return(strdup(""));
	if (strsSize == 1)
		return(strdup(strs[0]));

	qsort(strs, strsSize, sizeof(strs[0]), cmp);
	max = strlen(strs[0]);
	for (i = 1; i < strsSize; i++) {
		if (((t = comm_len(strs[i - 1], strs[i]))) < max) {
			max = t;
			k = i;
		}
	}
	if (max == 0)
		return(strdup(""));
	res = malloc((max + 1) * sizeof(char));
	memcpy(res, strs[k], max * sizeof(char));
	res[max] = 0;
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%s\n", longestCommonPrefix(argv + 1, argc - 1));
	return(0);
}
