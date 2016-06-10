#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val)
{
	struct ListNode *newhead, **prevp, *t;

	prevp = &newhead;
	while (head) {
		t = head;
		head = head->next;
		if (t->val == val)
			free(t);
		else {
			*prevp = t;
			prevp = &t->next;
		}
	}
	*prevp = 0;
	return(newhead);
}

int main(void)
{
}
