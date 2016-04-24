/*
 * Too slow
 */
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct stack {
	char	val;
	struct stack *next;
};

static char **res;
static int p, maxp;

static void addans(const char *s)
{
	if (res == NULL) {
		maxp = 8;
		p = 0;
		res = malloc(maxp * sizeof(*res));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p++] = strdup(s);
}

static char pop(struct stack **head)
{
	if (*head == NULL)
		return(0);
	struct stack *t;
	char	c;

	t = *head;
	*head = t->next;
	c = t->val;
	free(t);
	return(c);
}

static void push(struct stack **head, char c)
{
	struct stack *t = malloc(sizeof(*t));
	t->next = *head;
	t->val = c;
	*head = t;
}

static int isValid(char *s)
{
	struct stack *head;
	int	valid;
	char	c;

	head = NULL;
	valid = 1;
	for (; *s; s++) {
		switch (*s) {
		case '(':
			push(&head, *s);
			break;
		case ')':
			c = pop(&head);
			if (c != '(')
				valid = 0;
			break;
		default:
			valid = 0;
			break;
		}
		if (!valid)
			break;
	}
	if (head) {
		valid = 0;
		while (head)
			pop(&head);
	}
	return(valid);
}

char **generateParenthesis(int n, int *returnSize)
{
	if (n < 1) {
		*returnSize = 0;
		return(NULL);
	}

	uint64_t bit, cnt;
	char	buf[2 * n + 1];
	int	i;

	res = NULL;
	p = 0;
	n *= 2;
	cnt = 1 << n;
	buf[n] = 0;
	for (bit = 0; bit < cnt; bit++) {
		for (i = 0; i < n; i++)
			if (bit & (1 << i))
				buf[i] = '(';
			else
				buf[i] = ')';
		if (isValid(buf))
			addans(buf);
	}
	*returnSize = p;
	return(res);
}

int main(void)
{
	int	i;
	char **res = generateParenthesis(3, &i);
}
