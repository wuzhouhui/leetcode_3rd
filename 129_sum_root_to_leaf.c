#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static int sum, *buf, bufp, maxbufp;

static void addsum(void)
{
	int i, v;
	for (v = i = 0; i < bufp; i++)
		v = v *10 + buf[i];
	sum += v;
}

static void adddigit(int v)
{
	if (!buf) {
		maxbufp = 8;
		buf = malloc(maxbufp * sizeof(*buf));
	}
	if (bufp >= maxbufp) {
		maxbufp += 8;
		buf = realloc(buf, maxbufp * sizeof(*buf));
	}
	buf[bufp++] = v;
}

static void do_sum(const struct TreeNode *root)
{
	if (!root)
		return;
	adddigit(root->val);
	if (!root->left && !root->right) {
		addsum();
		goto out;
	}
	do_sum(root->left);
	do_sum(root->right);
out:
	bufp--;
}

int sumNumbers(struct TreeNode *root)
{
	sum = 0;
	buf = NULL;
	do_sum(root);
	free(buf);
	return(sum);
}

int main(void)
{
}
