#include <string.h>

#ifndef bool
#define bool int
#endif

bool isAnagram(char *s, char *t)
{
	static int arr1[26], arr2[26];
	int	i;

	memset(arr1, 0, sizeof(arr1));
	memset(arr2, 0, sizeof(arr2));
	for (i = 0; s[i]; i++)
		arr1[s[i] - 'a']++;
	for (i = 0; t[i]; i++)
		arr2[t[i] - 'a']++;
	return(!memcmp(arr1, arr2, sizeof(arr1)));
}
main(){}
