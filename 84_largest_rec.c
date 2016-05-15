#include <stdlib.h>

static struct stack {
	int	val;
	struct stack *next;
} *stack;

static int top(void)
{
	return(stack->val);
}

static void push(int i)
{
	struct stack *t = malloc(sizeof(*t));
	t->val = i;
	t->next = stack;
	stack = t;
}

static int pop(void)
{
	struct stack *t = stack;
	int	v = t->val;
	stack = stack->next;
	free(t);
	return(v);
}

int largestRectangleArea(int *heights, int heightsSize)
{
	int	max, i, t;

	stack = NULL;
	max = 0;
	i = 0;
	while (i < heightsSize) {
		if (!stack || heights[i] >= heights[top()]) {
			push(i++);
			continue;
		}
		t = pop();
		t = (!stack ? i : i - 1 - top()) * heights[t];
		if (t > max)
			max = t;
	}
	while (stack) {
		t = pop();
		t = (!stack ? i : i - 1 - top()) * heights[t];
		if (t > max)
			max = t;
	}
	return(max);
}

int main(void)
{
}
