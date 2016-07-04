#include <string.h>
#include <ctype.h>

static int inline isvowel(char c)
{
	c = tolower(c);
	return(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char *reverseVowels(char *s)
{
	int l = 0, r = strlen(s) - 1;
	char c;
	while (l < r) {
		while (l < r && !isvowel(s[l]))
			l++;
		while (r > l && !isvowel(s[r]))
			r--;
		c = s[l];
		s[l] = s[r];
		s[r] = c;
		l++,r--;
	}
	return(s);
}
main(){}
