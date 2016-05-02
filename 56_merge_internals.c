#include <stdlib.h>

static struct Interval *res;
static int p, maxp;

struct Interval {
	int	start;
	int	end;
};

static void addans(const struct Interval *inte)
{
	if (!res) {
		maxp = 8;
		res = malloc(maxp * sizeof(*res));
	}
	if (p >= maxp) {
		maxp += 8;
		res = realloc(res, maxp * sizeof(*res));
	}
	res[p].start = inte->start;
	res[p].end = inte->end;
	p++;
}

static int cmp(const void *a, const void *b)
{
	struct Interval *i1 = (struct Interval *)a;
	struct Interval *i2 = (struct Interval *)b;
	if (i1->start != i2->start)
		return(i1->start - i2->start);
	return(i1->end - i2->end);
}

struct Interval *merge(struct Interval *intervals, int intervalsSize,
		int *returnSize)
{
	struct Interval inte;
	int	next, i;

	res = NULL;
	p = 0;
	qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
	next = 0;
	while (next < intervalsSize) {
		inte.start = intervals[next].start;
		inte.end = intervals[next].end;
		for (i = next + 1; i < intervalsSize; i++) {
			if (intervals[i].start > inte.end)
				break;
			if (intervals[i].end > inte.end)
				inte.end = intervals[i].end;
		}
		addans(&inte);
		next = i;
	}
	*returnSize = p;
	return(res);
}

int main(void)
{
}
