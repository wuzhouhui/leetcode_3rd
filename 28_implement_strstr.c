#include <string.h>

int strStr(char *haystack, char *needle)
{
	char	*p;
	if ((p = strstr(haystack, needle)) == NULL)
		return(-1);
	else
		return((int)(p - haystack));
}

int main(void)
{
}
