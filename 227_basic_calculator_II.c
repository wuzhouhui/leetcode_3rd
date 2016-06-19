#include <ctype.h>

int calculate(char *s)
{
	int sum, term, op, t;
	int valid = 0;

	sum = 0;
	term = 1;
	op = '*';
	while (*s) {
		switch (*s) {
		case ' ':
			s++;
			break;
		case '+':
			sum += term;
			term = 1;
			op = '*';
			s++;
			valid = 0;
			break;
		case '-':
			sum += term;
			term = -1;
			op = '*';
			s++;
			valid = 0;
			break;
		case '*':
			op = '*';
			s++;
			break;
		case '/':
			op = '/';
			s++;
			break;
		default:
			t = 0;
			while (isdigit(*s)) {
				t = t * 10 + *s - '0';
				s++;
			}
			valid = 1;
			if (op == '*')
				term *= t;
			else
				term /= t;
			break;
		}
	}
	return(valid ? sum + term : sum);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", calculate(argv[1]));
	return(0);
}
