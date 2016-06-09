#include <string.h>
#include <stdlib.h>

static int *split(char *version, int *len)
{
	int *res = NULL;
	int	maxp = 0;
	char *v;

	v = strtok(version, ".");
	*len = 0;
	while (v) {
		if (*len >= maxp) {
			maxp += 8;
			res = realloc(res, maxp * sizeof(*res));
		}
		res[(*len)++] = atoi(v);
		v = strtok(NULL, ".");
	}
	return(res);
}

int compareVersion(char *version1, char *version2)
{
	int	*v1, *v2, v1len, v2len;
	int	i, j;

	v1 = split(version1, &v1len);
	v2 = split(version2, &v2len);
	for (i = j = 0;;) {
		if (i >= v1len && j >= v2len)
			break;
		else if (i >= v1len) {
			if (v2[j])
				return(-1);
			j++;
			continue;
		} else if (j >= v2len) {
			if (v1[i])
				return(1);
			i++;
			continue;
		}
		if (v1[i] == v2[j]) {
			i++, j++;
			continue;
		} else if (v1[i] < v2[j])
			return(-1);
		else
			return(1);
	}
	if (i < v1len)
		return(1);
	else if (j < v2len)
		return(-1);
	else
		return(0);
}

int main(void)
{
	char v1[] = "1";
	char v2[] = "1.0";
	compareVersion(v1, v2);
	return(0);
}
