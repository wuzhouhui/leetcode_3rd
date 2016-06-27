#include <stdio.h>
#include <stdlib.h>

char *getHint(char *secret, char *guess)
{
	int arr[10] = { 0 };
	int i, bulls, cows;
	char *res;

	bulls = cows = 0;
	for (i = 0; secret[i]; i++)
		if (secret[i] == guess[i])
			bulls++;
		else
			arr[secret[i] - '0']++;
	for (i = 0; guess[i]; i++)
		if (secret[i] != guess[i] && arr[guess[i] - '0'])
			cows++, arr[guess[i] - '0']--;
	res = malloc(128 * sizeof(*res));
	sprintf(res, "%dA%dB", bulls, cows);
	return(res);
}

main(){}
