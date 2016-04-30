#include <string.h>
#include <stdlib.h>

static char *res;
static int p, maxp;

static void addans(char c)
{
	if (!res) {
		p = 0;
		maxp = 8;
		res = malloc(maxp * sizeof(*res));
	}
	if ((p + 1) >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p++] = c;
}

char *countAndSay(int n)
{
	char	*prev;
	char	c;
	int	i, cnt;

	prev = NULL;
	res = strdup("1");
	while (--n > 0) {
		if (prev)
			free(prev);
		prev = res;
		res = NULL;
		i = 0;
		while (prev[i]) {
			c = prev[i];
			cnt = 0;
			while (prev[i] && prev[i] == c) {
				cnt++;
				i++;
			}
			addans(cnt + '0');
			addans(c);
		}
		res[p] = 0;
	}
	return(res);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("%s\n", countAndSay(5));
}
