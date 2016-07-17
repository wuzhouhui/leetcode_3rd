#include <string.h>
#include <stdlib.h>

static struct {
	int start;
	int len;
} split[4];

static char **res;
static int maxp, p;

static void addans(const char *s, int len)
{
	char *buf = calloc(len + 3 + 1, sizeof(*s));
	int bufp, flag, i;
	bufp = flag = 0;
	for (i = 0; i < 4; i++) {
		if (flag)
			buf[bufp++] = '.';
		else
			flag = 1;
		strncpy(buf + bufp, s + split[i].start, split[i].len);
		bufp += split[i].len;
	}
	if (res == NULL) {
		maxp = 8;
		p = 0;
		res = malloc(maxp * sizeof(*res));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p++] = buf;
}

static void do_restore(const char *s, int start, int part)
{
	int i, t;
	char buf[5];

	if (part >= 4) {
		if (s[start] == 0)
			addans(s, start);
		return;
	}
	for (i = 0; s[start + i] && i < 3; i++) {
		strncpy(buf, s + start, i + 1);
		buf[i + 1] = 0;
		if (i > 0 && buf[0] == '0')
			return;
		t = atoi(buf);
		if (t > 255)
			return;
		split[part].start = start;
		split[part].len = i + 1;
		do_restore(s, start + i + 1, part + 1);
	}
}

char **restoreIpAddresses(char *s, int *returnSize)
{
	res = NULL;
	p = 0;
	do_restore(s, 0, 0);
	*returnSize = p;
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	char s[] = "010010";
	int n;
	char **res = restoreIpAddresses(s, &n);
	while (n-- > 0)
		printf("%s\n", res[n]);
	return(0);
}
