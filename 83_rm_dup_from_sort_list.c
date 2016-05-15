#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	struct ListNode *newhead, **headp, *next, *t;

	newhead = NULL;
	headp = &newhead;
	while (head) {
		next = head;
		head = head->next;
		next->next = NULL;
		while (head && head->val == next->val) {
			t = head;
			head = head->next;
			free(t);
		}
		*headp = next;
		headp = &next->next;
	}
	return(newhead);
}

int main(void)
{
}
