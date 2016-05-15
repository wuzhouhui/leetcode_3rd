#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define STEP	16

static int p, maxsz, *intptr;

static void in_trav(struct TreeNode *);

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
	if (!root) {
		*returnSize = 0;
		return(NULL);
	}

	maxsz = STEP;
	p = 0;
	intptr = malloc(maxsz * sizeof(int));
	in_trav(root);

	*returnSize = p;
	return(intptr);
}

static void in_trav(struct TreeNode *root)
{
	if (!root)
		return;
	in_trav(root->left);
	if (p >= maxsz) {
		maxsz += STEP;
		intptr = realloc(intptr, maxsz * sizeof(int));
	}
	*(intptr + p++) = root->val;
	in_trav(root->right);
}

int main(void)
{}
