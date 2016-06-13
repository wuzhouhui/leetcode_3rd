struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static void do_invert(struct TreeNode *root)
{
	if (!root)
		return;
	struct TreeNode *t = root->left;
	root->left = root->right;
	root->right = t;
	do_invert(root->left);
	do_invert(root->right);
}

struct TreeNode *invertTree(struct TreeNode *root)
{
	do_invert(root);
	return(root);
}
main(){}
