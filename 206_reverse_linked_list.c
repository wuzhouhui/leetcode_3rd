struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
	struct ListNode *newhead = 0, *t;
	while (head) {
		t = head;
		head = head->next;
		t->next = newhead;
		newhead = t;
	}
	return(newhead);
}
main(){}
