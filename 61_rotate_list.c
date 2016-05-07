struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
	int	c;
	struct ListNode *newhead, *t, *left, *right;

	c = 0;
	for (t = head; t; t = t->next)
		c++;
	if (c == 0 || (k %= c) == 0)
		return(head);
	c -= k;
	left = head;
	while (--c > 0)
		left = left->next;
	right = left->next;
	while (right->next)
		right = right->next;
	newhead = left->next;
	left->next = 0;
	right->next = head;
	return(newhead);
}

int main(void)
{
}
