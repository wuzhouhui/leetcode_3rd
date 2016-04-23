#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
	int	i;
	struct ListNode **pp, *t;

	if (!head)
		return(head);
	t = head;
	for (i = 1; i < n; i++)
		t = t->next;
	pp = &head;
	while (t->next) {
		t = t->next;
		pp = &(*pp)->next;
	}
	t = *pp;
	*pp = t->next;
	free(t);
	return(head);
}

int main(void)
{
}
