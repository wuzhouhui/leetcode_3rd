struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int m, int n)
{
	if (!head || m == n)
		return(head);

	struct ListNode *revhead, *t1, *t2, *t3, **prevp;
	struct ListNode *start;

	prevp = &head;
	n -= m;
	while (--m > 0)
		prevp = &(*prevp)->next;

	start = t1 = *prevp;
	t2 = start;
	while (n-- > 0)
		t2 = t2->next;
	t3 = t2->next;
	t2->next = 0;
	revhead = 0;
	while (start) {
		t2 = start;
		start = start->next;
		t2->next = revhead;
		revhead = t2;
	}

	*prevp = revhead;
	t1->next = t3;
	return(head);
}

#include <stdlib.h>

int main(void)
{
	struct ListNode *head;

	head = malloc(sizeof(*head));
	head->val = 2;
	head->next = calloc(1, sizeof(*head));
	head->next->val = 1;
	reverseBetween(head, 1, 2);
}
