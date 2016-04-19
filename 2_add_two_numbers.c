#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *res, *t, **pp;
	int	c, s;

	c = 0;
	res = NULL;
	pp = &res;
	while (l1 && l2) {
		s = l1->val + l2->val + c;
		l1 = l1->next;
		l2 = l2->next;
		if (s >= 10) {
			c = 1;
			s -= 10;
		} else
			c = 0;
		t = malloc(sizeof(*t));
		t->val = s;
		t->next = NULL;
		*pp = t;
		pp = &t->next;
	}
	while (l1) {
		s = l1->val + c;
		l1 = l1->next;
		if (s >= 10) {
			c = 1;
			s -= 10;
		} else
			c = 0;
		t = malloc(sizeof(*t));
		t->val = s;
		t->next = NULL;
		*pp = t;
		pp = &t->next;
	}
	while (l2) {
		s = l2->val + c;
		l2 = l2->next;
		if (s >= 10) {
			c = 1;
			s -= 10;
		} else
			c = 0;
		t = malloc(sizeof(*t));
		t->val = s;
		t->next = NULL;
		*pp = t;
		pp = &t->next;
	}
	if (c) {
		t = malloc(sizeof(*t));
		t->val = c;
		t->next = NULL;
		*pp = t;
		pp = &t->next;
	}
	return(res);
}

int main(void)
{
}
