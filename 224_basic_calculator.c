#include <stdlib.h>
#include <ctype.h>

struct stack {
	int	val;
	struct stack *next;
};

static int top(struct stack **stack)
{
	if (*stack)
		return((*stack)->val);
	else
		return(0);
}

static int pop(struct stack **stack)
{
	if (!*stack)
		return(0);
	struct stack *t = *stack;
	int v = t->val;
	*stack = t->next;
	free(t);
	return(v);
}

static void push(struct stack **stack, int v)
{
	struct stack *t = malloc(sizeof(*t));
	t->val = v;
	t->next = *stack;
	*stack = t;
}

int calculate(char *s)
{
	int op, op1, op2;
	struct stack *operands, *operator;

	operands = NULL;
	operator = NULL;
	while (*s) {
		switch (*s) {
		case ' ':
			s++;
			break;
		case '(':
			push(&operator, '(');
			s++;
			break;
		case ')':
			while ((op = pop(&operator)) != '(') {
				op1 = pop(&operands);
				op2 = pop(&operands);
				op1 = (op == '+' ? op1 + op2 : op2 - op1);
				push(&operands, op1);
			}
			if (top(&operator) == '-') {
				pop(&operator);
				op1 = pop(&operands);
				op2 = pop(&operands);
				op1 = op2 - op1;
				push(&operands, op1);
			}
			s++;
			break;
		case '+':
			push(&operator, '+');
			s++;
			break;
		case '-':
			push(&operator, '-');
			s++;
			break;
		default:
			op = 0;
			while (isdigit(*s)) {
				op = op * 10 + *s - '0';
				s++;
			}
			push(&operands, op);
			if (top(&operator) == '-') {
				pop(&operator);
				op1 = pop(&operands);
				op2 = pop(&operands);
				op1 = op2 - op1;
				push(&operands, op1);
			}
			break;
		}
	}
	while ((op = pop(&operator)) != 0) {
		op1 = pop(&operands);
		op2 = pop(&operands);
		op1 += op2;
		push(&operands, op1);
	}
	return(pop(&operands));
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", calculate(argv[1]));
	return(0);
}
