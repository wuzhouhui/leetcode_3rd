#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
	struct ListNode *head, **pptr;
	struct ListNode *t;

	head = NULL;
	pptr = &head;
	while (l1 && l2) {
		t = calloc(1, sizeof(*t));
		if (l1->val < l2->val) {
			t->val = l1->val;
			l1 = l1->next;
		} else {
			t->val = l2->val;
			l2 = l2->next;
		}
		*pptr = t;
		pptr = &t->next;
	}
	while (l1) {
		t = calloc(1, sizeof(*t));
		t->val = l1->val;
		*pptr = t;
		pptr = &t->next;
		l1 = l1->next;
	}
	while (l2) {
		t = calloc(1, sizeof(*t));
		t->val = l2->val;
		*pptr = t;
		pptr = &t->next;
		l2 = l2->next;
	}
	return(head);
}

void main(void)
{
}
