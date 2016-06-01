#include <string.h>

#ifndef bool
#define bool int
#endif

static int contain(char *s, int start, int len, char **wordDict, 
		int wordDictSize)
{
	int	i;

	for (i = 0; i < wordDictSize; i++) {
		if (strlen(wordDict[i]) != len)
			continue;
		if (!strncmp(s + start, wordDict[i], len))
			return(1);
	}
	return(0);
}

bool wordBreak(char *s, char **wordDict, int wordDictSize)
{

	int	len = strlen(s), i, j;
	char	b[len + 1];

	memset(b, 0, sizeof(b));
	for (i = 0; i <= len; i++) {
		if (i == 0) {
			b[0] = 1;
			continue;
		}
		if (contain(s, 0, i, wordDict, wordDictSize)) {
			b[i] = 1;
			continue;
		}
		for (j = i - 1; j > 0; j--) {
			if (b[j] && contain(s, j, i - j, wordDict, 
						wordDictSize)) {
				b[i] = 1;
				break;
			}
		}
		if (j == 0)
			b[i] = 0;
	}
	return(b[len]);
}

#include <stdio.h>

int main(void)
{
	char *s = "leetcode";
	char *dic[] = { "leet", "code" };
	printf("%d\n", wordBreak(s, dic, sizeof(dic) / sizeof(*dic)));
	return(0);
}
