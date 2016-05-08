#include <string.h>

int minDistance(char *word1, char *word2)
{
	int w1len = strlen(word1);
	int w2len = strlen(word2);
	static int dist[512][512];
	int	del, ins, rep, i, j;

	if (w1len == 0 || w2len == 0)
		return(w1len ? w1len : w2len);

	for (i = 0; i < w1len; i++)
		dist[i][0] = i;
	for (j = 0; j < w2len; j++)
		dist[0][j] = j;
	for (i = 0; i < w1len; i++) {
		for (j = 0; j < w2len; j++) {
			if (word1[i] == word2[j]) {
				dist[i + 1][j + 1] = dist[i][j];
				continue;
			}
			ins = dist[i + 1][j] + 1;
			del = dist[i][j + 1] + 1;
			rep = dist[i][j] + 1;
			if (del < ins)
				ins = del;
			if (rep < ins)
				ins = rep;
			dist[i + 1][j + 1] = ins;
		}
	}
	return(dist[w1len][w2len]);
}

int main(void)
{
	minDistance("ab", "de");
}
