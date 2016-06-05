#include <string.h>

#define IN 0
#define OUT 1

static void trim(char *s)
{
	int	prev, i, j;
	for (prev = i = j = 0; s[j]; j++) {
		if (s[j] == ' ') {
			if (prev == 0)
				continue;
			else if (prev == ' ')
				continue;
			else {
				s[i++] = ' ';
				prev = ' ';
			}
		} else {
			s[i++] = s[j];
			prev = s[j];
		}
	}
	if (i > 0 && s[i - 1] == ' ')
		i--;
	s[i] = 0;
}

static void reverse(char *s, int l, int r)
{
	int	t;
	while (l < r) {
		t = s[l];
		s[l] = s[r];
		s[r] = t;
		l++, r--;
	}
}

void reverseWords(char *s)
{
	int	i, inout, start;
	trim(s);
	reverse(s, 0, strlen(s) - 1);
	i = 0;
	inout = OUT;
	while (1) {
		if (s[i] == ' ') {
			reverse(s, start, i - 1);
			i++;
			inout = OUT;
		} else if (s[i] == 0) {
			if (inout == IN)
				reverse(s, start, i - 1);
			break;
		} else if (inout == OUT) {
			inout = IN;
			start = i;
			i++;
		} else
			i++;
	}
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	reverseWords(argv[1]);
	printf("%s\n", argv[1]);
	return(0);
}
