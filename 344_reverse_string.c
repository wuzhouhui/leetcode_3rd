#include <string.h>

char *reverseString(char *s)
{
	int l = 0, r = strlen(s) - 1, c;
	while (l < r) {
		c = s[l];
		s[l] = s[r];
		s[r] = c;
		l++, r--;
	}
	return(s);
}
main(){}
