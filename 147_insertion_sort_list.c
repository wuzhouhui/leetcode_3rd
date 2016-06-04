struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *head)
{
	struct ListNode *newhead, *p, **pp;

	newhead = 0;
	while (head) {
		p = head;
		head = head->next;
		p->next = 0;
		pp = &newhead;
		while (*pp && (*pp)->val < p->val)
			pp = &(*pp)->next;
		p->next = *pp;
		*pp = p;
	}
	return(newhead);
}

int main(void)
{
}
