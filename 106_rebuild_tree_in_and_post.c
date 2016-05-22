#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static struct TreeNode *do_build(const int *inorder, const int *postorder,
		int len)
{
	if (len <= 0)
		return(NULL);
	struct TreeNode *node = malloc(sizeof(*node));
	int	i;

	node->val = postorder[len - 1];
	for (i = 0; i < len; i++)
		if (inorder[i] == node->val)
			break;
	node->left = do_build(inorder, postorder, i);
	node->right = do_build(inorder + i + 1, postorder + i, len - 1 - i);
	return(node);
}

struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder,
		int postorderSize)
{
	return(do_build(inorder, postorder, inorderSize));
}

int main(void)
{
}
