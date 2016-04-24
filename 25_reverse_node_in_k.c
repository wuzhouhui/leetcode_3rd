struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
	int	i;
	struct ListNode *start, *end, *stack, **pptr, **pptr2, *next;

	pptr = &head;
	next = head;
	while (next) {
		start = end = next;
		for (i = 1; i < k; i++)
			if (end->next)
				end = end->next;
			else
				break;
		if (i < k) {
			*pptr = next;
			return(head);
		}
		next = end->next;
		stack = 0;
		pptr2 = &start->next;
		while (start != next) {
			end = start;
			start = start->next;
			end->next = stack;
			stack = end;
		}
		*pptr = stack;
		pptr = pptr2;
	}
	return(head);
}

int main(void)
{
}
