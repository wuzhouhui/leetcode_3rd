struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int countNodes(struct TreeNode *root)
{
	if (!root)
		return(0);
	int lh, rh;
	struct TreeNode *t;
	for (t = root, lh = 0; t; t = t->left)
		lh++;
	for (t = root, rh = 0; t; t = t->right)
		rh++;
	if (lh == rh)
		return((1 << lh) - 1);
	return(countNodes(root->left) + countNodes(root->right) + 1);
}

main(){}
