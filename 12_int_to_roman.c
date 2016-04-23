#include <string.h>
#include <stdlib.h>

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

char *intToRoman(int num)
{
	int	i;
	char	*res;

	res = malloc(32 * sizeof(char));
	res[0] = 0;
	for (i = 0; i < sizeof(r) / sizeof(r[0]); i++) {
		while (num >= r[i]) {
			strcat(res, romans[i]);
			num -= r[i];
		}
	}
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%s\n", intToRoman(atoi(argv[1])));
	return(0);
}
