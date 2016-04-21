#include <stdlib.h>
#include <string.h>

char *longestPalindrome(char *s)
{
	if (s == NULL || s[0] == 0)
		return(strdup(""));
	int	i, j, k;
	int	left, right, t, max;
	char	*res;

	max = 0;
	for (k = 0; s[k]; k++) {
		i = k - 1;
		j = k + 1;
		while (i >= 0 && s[j]) {
			if (s[i] != s[j])
				break;
			i--, j++;
		}
		i++, j--;
		if ((t = j - i + 1) > max) {
			max = t;
			left = i;
			right = j;
		}

		i = k;
		j = k + 1;
		while (i >= 0 && s[j]) {
			if (s[i] != s[j])
				break;
			i--, j++;
		}
		i++, j--;
		if ((t = j - i + 1) > max) {
			max = t;
			left = i;
			right = j;
		}
	}

	res = malloc(max + 1);
	memcpy(res, s + left, max * sizeof(char));
	res[max] = 0;
	return(res);
}

int main(void)
{
}
