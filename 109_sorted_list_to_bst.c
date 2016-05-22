#include <stdlib.h>

struct ListNode {
	int	val;
	struct ListNode *next;
};

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static struct TreeNode *do_build(const struct ListNode *head, int len)
{
	if (!head || len <= 0)
		return(NULL);
	const struct ListNode *t;
	struct TreeNode *root;
	int	i;

	t = head;
	i = 1;
	while (i <= len / 2) {
		t = t->next;
		i++;
	}
	root = malloc(sizeof(*root));
	root->val = t->val;
	root->left = do_build(head, i - 1);
	root->right = do_build(t->next, len - i);
	return(root);
}

struct TreeNode *sortedListToBST(struct ListNode *head)
{
	int	len;
	struct ListNode *t;

	for (len = 0, t = head; t; t = t->next)
		len++;
	return(do_build(head, len));
}

int main(void)
{
	struct ListNode head = { 0, 0 };
	sortedListToBST(&head);
	return(0);
}
