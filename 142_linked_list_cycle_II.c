struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head)
{
	if (!head || !head->next)
		return(0);
	struct ListNode *p1 = head;
	struct ListNode *p2 = head;
	do {
		if (!p2 || !p2->next)
			return(0);
		p2 = p2->next;
		p2 = p2->next;
		p1 = p1->next;
	} while (p1 != p2);
	p1 = head;
	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return(p1);
}

int main(void)
{
}
