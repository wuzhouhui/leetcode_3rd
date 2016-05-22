#include <stdlib.h>
#include <string.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#ifndef bool
#define bool
#endif

static int *inorder1, *inorder2, p, maxp;

static void leftright(const struct TreeNode *root)
{
	if (!root)
		return;
	leftright(root->left);
	if (!inorder1) {
		maxp = 8;
		p = 0;
		inorder1 = malloc(maxp * sizeof(inorder1[0]));
	}
	if (p >= maxp) {
		maxp += 8;
		inorder1 = realloc(inorder1, maxp * sizeof(inorder1[0]));
	}
	inorder1[p++] = root->val;
	leftright(root->right);
}

static void rightleft(const struct TreeNode *root)
{
	if (!root)
		return;
	rightleft(root->right);
	inorder2[p++] = root->val;
	rightleft(root->left);
}

static left_pre(const struct TreeNode *root)
{
	if (!root)
		return;
	inorder1[p++] = root->val;
	left_pre(root->left);
	left_pre(root->right);
}

static right_pre(const struct TreeNode *root)
{
	if (!root)
		return;
	inorder2[p++] = root->val;
	right_pre(root->right);
	right_pre(root->left);
}

bool isSymmetric(struct TreeNode *root)
{
	inorder1 = inorder2 = 0;
	p = 0;
	leftright(root);
	inorder2 = malloc(p * sizeof(inorder2[0]));
	p = 0;
	rightleft(root);
	p = !memcmp(inorder1, inorder2, p * sizeof(inorder1[0]));
	if (p) {
		p = 0;
		left_pre(root);
		p = 0;
		right_pre(root);
		p = !memcmp(inorder1, inorder2, p * sizeof(inorder1[0]));
	}
	free(inorder1);
	free(inorder2);
	return(p);
}

int main(void)
{
}
