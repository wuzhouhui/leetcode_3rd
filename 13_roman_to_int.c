#include <string.h>

static char *romans[] = {
	/* 1000 */
	"M",
	/* 100, 400, 500, 900 */
	"CM", "D", "CD", "C",
	/* 10, 40, 50, 90 */
	"XC", "L", "XL", "X",
	/* 1, 4, 5, 9 */
	"IX", "V", "IV", "I",
};

static int r[] = {
	1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1,
};

int romanToInt(char *s)
{
	int	res, t, i;

	res = 0;
	for (i = 0; i < 13; i++) {
		t = strlen(romans[i]);
		while (!strncmp(s, romans[i], t)) {
			res += r[i];
			s += t;
		}
	}
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", romanToInt(argv[1]));
	return(0);
}
