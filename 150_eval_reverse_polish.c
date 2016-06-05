#include <stdlib.h>
#include <string.h>

struct stack {
	int	val;
	struct stack *next;
};

static struct stack *stack;

static int pop(void)
{
	struct stack *t = stack;
	int	v = t->val;
	stack = stack->next;
	free(t);
	return(v);
}

static void push(int v)
{
	struct stack *t = malloc(sizeof(*t));
	t->val = v;
	t->next = stack;
	stack = t;
}

int evalRPN(char **tokens, int tokensSize)
{
	if (tokensSize <= 0)
		return(0);
	int	r, i;
	stack = NULL;
	for (i = 0; i < tokensSize; i++) {
		if (strlen(tokens[i]) == 1) {
			switch (tokens[i][0]) {
			case '+':
				push(pop() + pop());
				break;
			case '-':
				r = pop();
				push(pop() - r);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				r = pop();
				push(pop() / r);
				break;
			default:
				push(tokens[i][0] - '0');
				break;
			}
		} else {
			push(atoi(tokens[i]));
		}
	}
	return(pop());
}

int main(void)
{
}
