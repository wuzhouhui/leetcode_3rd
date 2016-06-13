#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

void deleteNode(struct ListNode *node)
{
	if (!node || !node->next)
		return;
	struct ListNode *t = node->next;
	node->val = t->val;
	node->next = t->next;
	free(t);
}

main(){}
