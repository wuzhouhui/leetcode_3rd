struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *sortList(struct ListNode *head)
{
	if (!head || !head->next)
		return(head);
	struct ListNode *h1, *h2, **pp1, **pp2, *t;
	int	dir;
	h1 = h2 = 0;
	pp1 = &h1;
	pp2 = &h2;
	dir = 0;
	while (head) {
		t = head;
		head = head->next;
		t->next = 0;
		if (dir) {
			*pp1 = t;
			pp1 = &t->next;
		} else {
			*pp2 = t;
			pp2 = &t->next;
		}
		dir = !dir;
	}
	h1 = sortList(h1);
	h2 = sortList(h2);
	pp1 = &head;
	while (h1 && h2) {
		if (h1->val < h2->val) {
			t = h1;
			h1 = h1->next;
		} else {
			t = h2;
			h2 = h2->next;
		}
		t->next = 0;
		*pp1 = t;
		pp1 = &t->next;
	}
	if (h1)
		*pp1 = h1;
	else if (h2)
		*pp1 = h2;
	return(head);
}

int main(void)
{
}
