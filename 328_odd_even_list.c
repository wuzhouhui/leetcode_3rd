struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *oddEvenList(struct ListNode *head)
{
	struct ListNode *oddhead, *evenhead, **oddptr, **evenptr;
	struct ListNode *t;
	int	flag;

	oddhead = evenhead = 0;
	oddptr = &oddhead;
	evenptr = &evenhead;
	flag = 1;
	while (head) {
		t = head;
		head = head->next;
		t->next = 0;
		if (flag) {
			flag = 0;
			*oddptr = t;
			oddptr = &t->next;
		} else {
			flag = 1;
			*evenptr = t;
			evenptr = &t->next;
		}
	}
	*oddptr = evenhead;
	return(oddhead);
}
main(){}
