#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

#ifndef bool
#define bool int
#endif

bool isPalindrome(struct ListNode *head)
{
	struct ListNode *headr, *t, *p;

	headr = 0;
	for (p = head; p; p = p->next) {
		t = malloc(sizeof(*t));
		t->val = p->val;
		t->next = headr;
		headr = t;
	}
	while (head && head->val == headr->val) {
		head = head->next;
		headr = headr->next;
	}
	return(head == NULL);
}

main(){}
