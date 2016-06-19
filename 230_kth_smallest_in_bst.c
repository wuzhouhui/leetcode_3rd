struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int count(const struct TreeNode *root)
{
	if (!root)
		return(0);
	return(count(root->left) + 1 + count(root->right));
}

int kthSmallest(struct TreeNode *root, int k)
{
	int c = count(root->left);
	c++;
	if (c == k)
		return(root->val);
	if (c > k)
		return(kthSmallest(root->left, k));
	return(kthSmallest(root->right, k - c));
}

int main(void)
{
}
