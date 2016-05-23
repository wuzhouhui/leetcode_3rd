struct TreeLinkNode {
	int	val;
	struct TreeLinkNode *left, *right, *next;
};

void connect(struct TreeLinkNode *root)
{
	if (!root)
		return;

	struct TreeLinkNode *head, *t;
	root->next = 0;
	while (1) {
		if (!root->left)
			break;
		head = root;
		while (head) {
			t = head;
			head = head->next;
			t->left->next = t->right;
			t->right->next = head ? head->left : 0;
		}
		root = root->left;
	}
}

int main(void)
{
}
