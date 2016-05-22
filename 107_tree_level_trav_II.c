#include <stdlib.h>

struct TreeNode {
	int	val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct queue {
	struct TreeNode *node;
	struct queue *next;
};

static int **res, *col, p, maxp;

static void enq(struct queue **head, struct queue **tail,
		struct TreeNode *node, int *len)
{
	if (!node)
		return;
	struct queue *t = malloc(sizeof(struct queue));
	t->node = node;
	t->next = 0;
	if (!*head) {
		*head = *tail = t;
	} else {
		(*tail)->next = t;
		*tail = t;
	}
	(*len)++;
}

static struct TreeNode *deq(struct queue **head)
{
	struct queue *t = *head;
	struct TreeNode *node = t->node;
	*head = (*head)->next;
	free(t);
	return(node);
}

static void add(int *tmpbuf, int len)
{
	if (!res) {
		maxp = 8;
		res = malloc(maxp * sizeof(int *));
		col = malloc(maxp * sizeof(int));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(int *));
		col = realloc(col, maxp * sizeof(int));
	}
	res[p] = tmpbuf;
	col[p] = len;
	p++;
}

int **levelOrderBottom(struct TreeNode *root, int **columnSizes,
		int *returnSize)
{
	struct queue *q1head, *q1tail, *q2head, *q2tail;
	int	qlen, i, *tmpbuf, len;
	struct TreeNode *node;
	int	l, r;

	res = 0;
	col = 0;
	p = 0;
	q1head = q2head = 0;
	qlen = 0;

	enq(&q1head, &q1tail, root, &qlen);
	while (qlen) {
		tmpbuf = malloc(qlen * sizeof(int));
		len = qlen;
		qlen = 0;
		i = 0;
		while (q1head) {
			node = deq(&q1head);
			enq(&q2head, &q2tail, node->left, &qlen);
			enq(&q2head, &q2tail, node->right, &qlen);
			tmpbuf[i++] = node->val;
		}
		add(tmpbuf, len);
		tmpbuf = 0;
		q1head = q2head;
		q1tail = q2tail;
		q2head = 0;
	}
	*columnSizes = col;
	*returnSize = p;
	l = 0;
	r = p - 1;
	while (l < r) {
		tmpbuf = res[l];
		res[l] = res[r];
		res[r] = tmpbuf;
		l++, r--;
	}
	l = 0;
	r = p - 1;
	while (l < r) {
		len = col[l];
		col[l] = col[r];
		col[r] = len;
		l++, r--;
	}
	return(res);
}

int main(void)
{
}
