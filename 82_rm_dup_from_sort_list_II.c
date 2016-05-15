#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
	struct ListNode *newhead, **headp;
	struct ListNode *next, *t;
	int	val;

	newhead = NULL;
	headp = &newhead;
	while (head) {
		next = head;
		head = head->next;
		next->next = NULL;
		val = next->val;
		while (head && head->val == val) {
			if (next) {
				free(next);
				next = NULL;
			}
			t = head;
			head = head->next;
			free(t);
		}
		if (next) {
			*headp = next;
			headp = &next->next;
		}
	}
	return(newhead);
}

int main(void)
{
}
