#include <string.h>
#include <stdlib.h>

static void reverse(char *str)
{
	int	l, r, t;
	l = 0;
	r = strlen(str) - 1;
	while (l < r) {
		t = str[l];
		str[l] = str[r];
		str[r] = t;
		l++;
		r--;
	}
}

static void str2asc(char *str)
{
	while (*str) {
		*str -= '0';
		str++;
	}
}

char *multiply(char *num1, char *num2)
{
	char	*res, *buf;
	int	l1, l2, len, i, j, c;
	int	p, t;

	l1 = strlen(num1);
	l2 = strlen(num2);
	len = l1 + l2;
	res = malloc((len + 1) * sizeof(*res));
	buf = malloc((len + 1) * sizeof(*buf));
	reverse(num1);
	reverse(num2);
	str2asc(num1);
	str2asc(num2);

	memset(res, 0, (len + 1) * sizeof(*res));
	for (i = 0; i < l2; i++) {
		c = 0;
		memset(buf, 0, (len + 1) * sizeof(*buf));
		p = i;
		for (j = 0; j < l1; j++) {
			t = num1[j] * num2[i] + c;
			c = t / 10;
			t %= 10;
			buf[p++] = t;
		}
		if (c)
			buf[p++] = c;

		c = 0;
		for (j = 0; j < len; j++) {
			res[j] += buf[j] + c;
			c = res[j] / 10;
			res[j] %= 10;
		}
	}

	for (i = len - 1; i >= 0; i--)
		if (res[i])
			break;
	if (i < 0) {
		strcpy(res, "0");
		return(res);
	}

	len = i + 1;
	for (i = 0; i < len; i++)
		res[i] += '0';
	res[len] = 0;
	reverse(res);
	return(res);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	char	s1[] = "123";
	char	s2[] = "32";
	printf("%s\n", multiply(s1, s2));
	return(0);
}
