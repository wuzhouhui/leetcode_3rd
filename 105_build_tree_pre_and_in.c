#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static struct TreeNode *do_build(const int *pre, const int *in, int len)
{
	if (len <= 0)
		return(NULL);
	struct TreeNode *node = malloc(sizeof(*node));
	int	i;
	node->val = pre[0];
	for (i = 0; i < len; i++)
		if (in[i] == node->val)
			break;
	node->left = do_build(pre + 1, in, i);
	node->right = do_build(pre + i + 1, in + i + 1, len - i - 1);
	return(node);
}

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder,
		int inorderSize)
{
	return(do_build(preorder, inorder, inorderSize));
}

int main(void)
{
}
