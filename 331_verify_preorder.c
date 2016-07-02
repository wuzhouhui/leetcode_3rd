#include <stdlib.h>
#include <ctype.h>

#ifndef bool
#define bool int
#endif

struct stack {
	int	left;
	struct stack *next;
};

static struct stack *peek(struct stack *s)
{
	return(s);
}

static void pop(struct stack **s)
{
	struct stack *t = *s;
	*s = t->next;
	free(t);
}

static void push(struct stack **s)
{
	struct stack *t = malloc(sizeof(*t));
	t->left = 2;
	t->next = *s;
	*s = t;
}

bool isValidSerialization(char *preorder)
{
	struct stack *stack, *t;

	if (*preorder == 0)
		return(0);

	stack = NULL;
	while (*preorder) {
		switch (*preorder) {
		case ',':
			preorder++;
			break;
		case '#':
			if (stack == NULL) {
				preorder++;
				goto out;
			}
			while (1) {
				t = peek(stack);
				if (--(t->left))
					break;
				pop(&stack);
				if (stack == NULL) {
					preorder++;
					goto out;
				}
			}
			preorder++;
			break;
		default:
			push(&stack);
			while (isdigit(*preorder))
				preorder++;
			break;
		}
	}

out:
	if (stack == NULL && *preorder == 0)
		return(1);
	while (stack)
		pop(&stack);
	return(0);
}

int main(void)
{
	return(0);
}
