struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA,
		struct ListNode *headB)
{
	if (!headA || !headB)
		return(0);
	int ca, cb;
	struct ListNode *p;

	for (p = headA, ca = 0; p; p = p->next)
		ca++;
	for (p = headB, cb = 0; p; p = p->next)
		cb++;
	if (ca > cb) {
		while (ca-- > cb)
			headA = headA->next;
	} else if (cb > ca) {
		while (cb-- > ca)
			headB = headB->next;
	}
	while (headA != headB) {
		headA = headA->next;
		headB = headB->next;
	}
	return(headA);
}

int main(void)
{
}
