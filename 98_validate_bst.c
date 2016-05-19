struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#ifndef bool
#define bool int
#endif

static int trav(struct TreeNode *root, int *max, int *min)
{
	int	lmax, lmin;
	int	r;

	*max = root->val;
	*min = root->val;
	if (root->left) {
		r = trav(root->left, &lmax, &lmin);
		if (r == 0 || lmax >= root->val)
			return(0);
		if (lmin < *min)
			*min = lmin;
	}
	if (root->right) {
		r = trav(root->right, &lmax, &lmin);
		if (r == 0 || lmin <= root->val)
			return(0);
		if (lmax > *max)
			*max = lmax;
	}
	return(1);
}

bool isValidBST(struct TreeNode *root)
{
	if (!root)
		return(1);
	int	m, n;
	return(trav(root, &m, &n));
}

int main(void)
{
}
