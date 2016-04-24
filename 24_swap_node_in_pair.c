struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
	if (!head || !head->next)
		return(head);
	struct ListNode **phead, *prev, *next;

	phead = &head;
	prev = head;
	next = head->next;
	while (prev && next) {
		*phead = next;
		prev->next = next->next;
		next->next = prev;
		phead = &prev->next;
		prev = *phead;
		if (prev)
			next = prev->next;
		else
			break;
	}
	return(head);
}

void main(void)
{
}
