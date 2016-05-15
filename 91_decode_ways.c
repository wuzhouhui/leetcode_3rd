#include <string.h>

int numDecodings(char *s)
{
	if (s[0] == 0)
		return(0);

	int	ways[strlen(s)], i;

	for (i = 0; s[i]; i++) {
		if (i == 0) {
			if (s[i] == '0')
				return(0);
			else
				ways[i] = 1;
			continue;
		}
		if (i == 1) {
			switch (s[i - 1]) {
			case '1':
				if (s[i] == '0')
					ways[i] = 1;
				else
					ways[i] = 2;
				break;
			case '2':
				if (s[i] >= '1' && s[i] <= '6')
					ways[i] = 2;
				else
					ways[i] = 1;
				break;
			default:
				if (s[i] == '0')
					return(0);
				ways[i] = 1;
			}
			continue;
		}

		switch (s[i - 1]) {
		case '1':
			if (s[i] == '0')
				ways[i] = ways[i - 2];
			else
				ways[i] = ways[i - 2] + ways[i - 1];
			break;
		case '2':
			if (s[i] >= '1' && s[i] <= '6')
				ways[i] = ways[i - 2] + ways[i - 1];
			else if (s[i] == '0')
				ways[i] = ways[i - 2];
			else
				ways[i] = ways[i - 1];
			break;
		default:
			if (s[i] == '0')
				return(0);
			ways[i] = ways[i - 1];
		}
		continue;
	}
	return(ways[i - 1]);
}

int main(void)
{
}
