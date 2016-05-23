struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static struct TreeNode *prev;

static void do_flatten(struct TreeNode *root)
{
	if (!root) {
		prev->right = 0;
		return;
	}
	struct TreeNode *l = root->left;
	struct TreeNode *r = root->right;
	root->left = 0;
	prev->right = root;
	prev = root;
	do_flatten(l);
	do_flatten(r);
}

void flatten(struct TreeNode *root)
{
	if (!root)
		return;
	struct TreeNode *l = root->left;
	struct TreeNode *r = root->right;
	root->left = 0;
	prev = root;
	do_flatten(l);
	do_flatten(r);
}

int main(void)
{
}
