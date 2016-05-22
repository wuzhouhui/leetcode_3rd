struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int minDepth(struct TreeNode *root)
{
	if (!root)
		return(0);
	int l = minDepth(root->left);
	int r = minDepth(root->right);
	if (root->left && root->right)
		return(l < r ? ++l : ++r);
	else
		return(l > r ? ++l : ++r);
}

int main(void)
{
}
