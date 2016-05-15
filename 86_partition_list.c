struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x)
{
	struct ListNode *lesshead, *t, **lessheadp, **headp;

	lesshead = 0;
	lessheadp = &lesshead;
	headp = &head;
	while (*headp) {
		if ((*headp)->val < x) {
			t = *headp;
			*headp = t->next;
			t->next = 0;
			*lessheadp = t;
			lessheadp = &t->next;
		} else {
			headp  = &(*headp)->next;
		}
	}
	*lessheadp = head;
	return(lesshead);
}

int main(void)
{
}
