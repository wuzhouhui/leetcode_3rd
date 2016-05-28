#include <ctype.h>

#ifndef bool
#define bool int
#endif

bool isPalindrome(char *s)
{
	if (!s)
		return(1);
	int i, j;
	for (i = j = 0; s[j]; j++)
		if (!isalnum(s[j]))
			continue;
		else
			s[i++] = s[j];
	s[i--] = 0;
	j = 0;
	while (j < i)
		if (tolower(s[j++]) != tolower(s[i--]))
			return(0);
	return(1);
}

int main(void)
{
}
