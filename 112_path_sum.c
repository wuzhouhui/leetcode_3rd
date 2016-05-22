struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#ifndef bool
#define bool int
#endif

static int do_sum(const struct TreeNode *root, int cur, int sum)
{
	if (!root)
		return(0);
	cur += root->val;
	if (!root->left && !root->right)
		return(cur == sum);
	if (do_sum(root->left, cur, sum))
		return(1);
	return(do_sum(root->right, cur, sum));
}

bool hasPathSum(struct TreeNode *root, int sum)
{
	return(do_sum(root, 0, sum));
}

int main(void)
{
}
