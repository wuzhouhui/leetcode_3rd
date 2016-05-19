struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#ifndef bool
#define bool int
#endif

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
	if (!p && !q)
		return(1);
	if (!(p && q) || p->val != q->val)
		return(0);
	if (!isSameTree(p->left, q->left))
		return(0);
	if (!isSameTree(p->right, q->right))
		return(0);
	return(1);
}

int main(void)
{
}
