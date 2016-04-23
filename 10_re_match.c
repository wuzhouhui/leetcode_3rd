#include <string.h>

#ifndef bool
#define bool int
#endif

bool isMatch(char *s, char *p)
{
	int	slen, i;
	slen = strlen(s);

	switch (*p) {
	case 0:
		return(*s == 0);
		break;
	case '.':
		if (*(p + 1) == '*')
			return(isMatch(s, p + 1));
		if (*s == 0)
			return(0);
		return(isMatch(s + 1, p + 1));
		break;
	case '*':
		if (*(p - 1) == '.') {
			for (i = 0; i <= slen; i++) {
				if (isMatch(s + i, p + 1))
					return(1);
			}
			return(0);
		}

		/* normal char */
		for (i = 0; i <= slen; i++) {
			if (i == 0) {
				if (isMatch(s, p + 1))
					return(1);
				continue;
			}
			if (s[i - 1] == *(p - 1)) {
				if (isMatch(s + i, p + 1))
					return(1);
				continue;
			}
			break;
		}
		return(0);
		break;
	default:
		if (*(p + 1) == '*')
			return(isMatch(s, p + 1));
		if (*s != *p)
			return(0);
		return(isMatch(s + 1, p + 1));
	}
	return(0);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", isMatch(argv[1], argv[2]));
	return(0);
}
