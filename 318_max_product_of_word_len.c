#include <stdint.h>
#include <string.h>

int maxProduct(char **words, int wordsSize)
{
	struct {
		uint32_t letters;
		int	len;
	} lettlen[wordsSize];
	int i, j, t, max;

	memset(lettlen, 0, sizeof(lettlen));
	for (i = 0; i < wordsSize; i++) {
		for (j = 0; words[i][j]; j++) {
			lettlen[i].letters |= 1 << (words[i][j] - 'a');
			lettlen[i].len++;
		}
	}
	max = 0;
	for (i = 0; i < wordsSize; i++) {
		for (j = i + 1; j < wordsSize; j++) {
			if (lettlen[i].letters & lettlen[j].letters)
				continue;
			t = lettlen[i].len * lettlen[j].len;
			if (t > max)
				max = t;
		}
	}
	return(max);
}
main(){}
