#include <string.h>
#include <stdlib.h>

static void revert(char *str, int len)
{
	char	t;
	int	i = 0;
	len--;
	while (i < len) {
		t = str[i];
		str[i] = str[len];
		str[len] = t;
		i++;
		len--;
	}
}

static void num2asc(char *s, int len)
{
	while (len-- > 0)
		*s++ += '0';
}

static void asc2num(char *s)
{
	while (*s) {
		*s -= '0';
		s++;
	}
}

char *addBinary(char *a, char *b)
{
	int	c, alen, blen, p;
	char	*sum;

	alen = strlen(a);
	blen = strlen(b);
	sum = malloc(((alen > blen ? alen : blen) + 2) * sizeof(*sum));
	revert(a, alen);
	revert(b, blen);
	asc2num(a);
	asc2num(b);
	p = 0;
	c = 0;
	while (alen && blen) {
		sum[p] = *a + *b + c;
		c = 0;
		if (sum[p] > 1) {
			sum[p] -= 2;
			c = 1;
		}
		p++;
		a++;
		b++;
		alen--;
		blen--;
	}
	while (alen) {
		sum[p] = *a + c;
		c = 0;
		if (sum[p] > 1) {
			sum[p] -= 2;
			c = 1;
		}
		p++;
		a++;
		alen--;
	}
	while (blen) {
		sum[p] = *b + c;
		c = 0;
		if (sum[p] > 1) {
			sum[p] -= 2;
			c = 1;
		}
		p++;
		b++;
		blen--;
	}
	if (c)
		sum[p++] = c;
	sum[p] = 0;
	num2asc(sum, p);
	revert(sum, p);
	return(sum);
}

#include <stdio.h>

int main(void)
{
	char a[] = "1";
	char b[] = "1";
	printf("%s\n", addBinary(a, b));
	return(0);
}
