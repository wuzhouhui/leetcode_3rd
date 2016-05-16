#include <string.h>

int numTrees(int n)
{
	if (n < 0)
		return(0);
	int i, j, tree[n + 1];
	memset(tree, 0, sizeof(tree));
	tree[0] = 1;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++)
			tree[i] += tree[j - 1] * tree[i - j];
	return(tree[n]);
}

int main(void)
{
}
