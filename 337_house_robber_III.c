#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int inline max(int a, int b)
{
	return(a > b ? a : b);
}

static int *do_rob(struct TreeNode *root)
{
	int *res = calloc(2, sizeof(*res));
	if (root == NULL)
		return(res);
	int *left = do_rob(root->left);
	int *right = do_rob(root->right);
	res[0] = max(left[0], left[1]) + max(right[0], right[1]);
	res[1] = root->val + left[0] + right[0];
	free(left);
	free(right);
	return(res);
}

int rob(struct TreeNode *root)
{
	int *res = do_rob(root);
	return(max(res[0], res[1]));
}

main(){}
