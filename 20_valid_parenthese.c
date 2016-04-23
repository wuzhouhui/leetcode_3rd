#include <stdlib.h>

#ifndef bool
#define bool int
#endif

struct stack {
	char	val;
	struct stack *next;
};

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

bool isValid(char *s)
{
	struct stack *head;
	int	valid;
	char	c;

	head = NULL;
	valid = 1;
	for (; *s; s++) {
		switch (*s) {
		case '(':
		case '[':
		case '{':
			push(&head, *s);
			break;
		case ')':
			c = pop(&head);
			if (c != '(')
				valid = 0;
			break;
		case ']':
			c = pop(&head);
			if (c != '[')
				valid = 0;
			break;
		case '}':
			c = pop(&head);
			if (c != '{')
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

void main(void)
{
}
