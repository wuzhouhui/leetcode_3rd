struct TreeLinkNode {
	int	val;
	struct TreeLinkNode *left, *right, *next;
};

void connect(struct TreeLinkNode *root)
{
	if (!root)
		return;
	struct TreeLinkNode *head, **prevp;

	root->next = 0;
	while (1) {
		prevp = &head;
		while (root) {
			if (root->left) {
				*prevp = root->left;
				prevp = &(*prevp)->next;
				if (root->right) {
					*prevp = root->right;
					prevp = &(*prevp)->next;
				}
			} else if (root->right) {
					*prevp = root->right;
					prevp = &(*prevp)->next;
			}
			root = root->next;
		}
		*prevp = 0;
		root = head;
		if (!root)
			break;
	}
}

int main(void)
{
}
