#include <stdlib.h>
#include <string.h>

static char **res;
static int p, maxp;
static char *ans;

static void addans(void)
{
	if (*ans == 0)
		return;
	if (res == NULL) {
		maxp = 8;
		p = 0;
		res = malloc(maxp * sizeof(*res));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p++] = strdup(ans);
}

static void do_comb(const char *digits, char *buf)
{
again:
	switch (*digits) {
	case '0':
		/* fall through */
	case '1':
		digits++;
		goto again;
		break;
	case '2':
		*buf = 'a'; do_comb(digits + 1, buf + 1);
		*buf = 'b'; do_comb(digits + 1, buf + 1);
		*buf = 'c'; do_comb(digits + 1, buf + 1);
		break;
	case '3':
		*buf = 'd'; do_comb(digits + 1, buf + 1);
		*buf = 'e'; do_comb(digits + 1, buf + 1);
		*buf = 'f'; do_comb(digits + 1, buf + 1);
		break;
	case '4':
		*buf = 'g'; do_comb(digits + 1, buf + 1);
		*buf = 'h'; do_comb(digits + 1, buf + 1);
		*buf = 'i'; do_comb(digits + 1, buf + 1);
		break;
	case '5':
		*buf = 'j'; do_comb(digits + 1, buf + 1);
		*buf = 'k'; do_comb(digits + 1, buf + 1);
		*buf = 'l'; do_comb(digits + 1, buf + 1);
		break;
	case '6':
		*buf = 'm'; do_comb(digits + 1, buf + 1);
		*buf = 'n'; do_comb(digits + 1, buf + 1);
		*buf = 'o'; do_comb(digits + 1, buf + 1);
		break;
	case '7':
		*buf = 'p'; do_comb(digits + 1, buf + 1);
		*buf = 'q'; do_comb(digits + 1, buf + 1);
		*buf = 'r'; do_comb(digits + 1, buf + 1);
		*buf = 's'; do_comb(digits + 1, buf + 1);
		break;
	case '8':
		*buf = 't'; do_comb(digits + 1, buf + 1);
		*buf = 'u'; do_comb(digits + 1, buf + 1);
		*buf = 'v'; do_comb(digits + 1, buf + 1);
		break;
	case '9':
		*buf = 'w'; do_comb(digits + 1, buf + 1);
		*buf = 'x'; do_comb(digits + 1, buf + 1);
		*buf = 'y'; do_comb(digits + 1, buf + 1);
		*buf = 'z'; do_comb(digits + 1, buf + 1);
		break;
	default:
		*buf = 0;
		addans();
		break;
	}
}

char **letterCombinations(char *digits, int *returnSize)
{
	res = NULL;
	p = 0;
	ans = malloc(strlen(digits) * 3 * sizeof(char) + 1);
	do_comb(digits, ans);
	free(ans);
	*returnSize = p;
	return(res);
}

void main(void)
{
	char	s[] = "0123";
	int	n;
	letterCombinations(s, &n);
}
