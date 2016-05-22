struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static struct TreeNode *prev, *one, *two, *three;

static void inorder(struct TreeNode *root)
{
	if (!root)
		return;
	inorder(root->left);
	if (prev && prev->val > root->val) {
		if (!one) {
			one = prev;
			two = root;
		} else {
			three = root;
		}
	}
	prev = root;
	inorder(root->right);
}

void recoverTree(struct TreeNode *root)
{
	int	t;
	prev = one = two = three = 0;
	inorder(root);
	if (!one)
		return;
	if (!three) {
		t = one->val;
		one->val = two->val;
		two->val = t;
	} else {
		t = one->val;
		one->val = three->val;
		three->val = t;
	}
}

int main(void)
{
}
