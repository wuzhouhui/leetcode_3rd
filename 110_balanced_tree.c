#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#ifndef bool
#define bool int
#endif

static int isbalan(const struct TreeNode *root, int *h)
{
	if (!root) {
		*h = 0;
		return(1);
	}

	int l, r;
	if (!isbalan(root->left, &l))
		return(0);
	if (!isbalan(root->right, &r))
		return(0);
	if (abs(l - r) > 1)
		return(0);
	*h = (l > r ? l : r) + 1;
	return(1);
}

bool isBalanced(struct TreeNode *root)
{
	int	h;
	return(isbalan(root, &h));
}

int main(void)
{
}
