struct ListNode {
	int	val;
	struct ListNode *next;
};

void reorderList(struct ListNode *head)
{
	if (!head || !head->next)
		return;
	struct ListNode *p1, *p2, *head2;

	p1 = p2 = head;
	while (p2) {
		p2 = p2->next;
		if (!p2)
			break;
		p2 = p2->next;
		if (!p2)
			break;
		p1 = p1->next;
	}
	head2 = 0;
	p2 = p1->next;
	p1->next = 0;
	while (p2) {
		p1 = p2;
		p2 = p2->next;
		p1->next = head2;
		head2 = p1;
	}
	while (head && head2) {
		p1 = head;
		head = head->next;
		p2 = head2;
		head2 = head2->next;
		p2->next = head;
		p1->next = p2;
	}
}

int main(void)
{
}
