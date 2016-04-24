#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
	struct ListNode *head, **pptr, *t, *l1, *l2;
	int	mid;

	if (!listsSize)
		return(NULL);
	if (listsSize == 1)
		return(lists[0]);

	mid = listsSize / 2;
	l1 = mergeKLists(lists, mid);
	l2 = mergeKLists(lists + mid, listsSize - mid);

	head = NULL;
	pptr = &head;
	while (l1 && l2) {
		if (l1->val < l2->val) {
			*pptr = l1;
			l1 = l1->next;
		} else {
			*pptr = l2;
			l2 = l2->next;
		}
		pptr = &(*pptr)->next;
	}
	if (l1)
		*pptr = l1;
	if (l2)
		*pptr = l2;
	return(head);
}

void main(void)
{
}
