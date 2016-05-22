struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
	if (!root)
		return(0);
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	return(l > r ? ++l : ++r);
}

int main(void)
{
}
