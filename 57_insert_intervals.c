#include <stdlib.h>
#include <string.h>

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

struct Interval *insert(struct Interval *intervals, int intervalsSize,
		struct Interval newInterval, int *returnSize)
{
	if (intervalsSize == 0) {
		res = malloc(sizeof(*res));
		memcpy(res, &newInterval, sizeof(*res));
		*returnSize = 1;
		return(res);
	}

	if (newInterval.end < intervals[0].start) {
		*returnSize = intervalsSize + 1;
		res = malloc(*returnSize * sizeof(*res));
		memcpy(&res[0], &newInterval, sizeof(res[0]));
		memcpy(&res[1], intervals, intervalsSize * sizeof(res[0]));
		return(res);
	}

	if (newInterval.start > intervals[intervalsSize - 1].end) {
		*returnSize = intervalsSize + 1;
		res = malloc(*returnSize * sizeof(*res));
		memcpy(&res[0], intervals, intervalsSize * sizeof(res[0]));
		memcpy(&res[intervalsSize], &newInterval, sizeof(res[0]));
		return(res);
	}

	int	next, i;

	for (i = 0; i < intervalsSize - 1; i++) {
		if (newInterval.start > intervals[i].end &&
				newInterval.end < intervals[i + 1].start) {
		*returnSize = intervalsSize + 1;
		res = malloc(*returnSize * sizeof(*res));
		memcpy(&res[0], intervals, (i + 1) * sizeof(res[0]));
		memcpy(&res[i + 1], &newInterval, sizeof(res[0]));
		memcpy(&res[i + 2], intervals + i + 1,
				(intervalsSize - i - 1) * sizeof(res[0]));
		return(res);
		}
	}

	for (i = 0; i < intervalsSize; i++) {
		if (newInterval.start > intervals[i].end)
			continue;
		if (newInterval.start < intervals[i].start)
			intervals[i].start = newInterval.start;
		if (newInterval.end > intervals[i].end)
			intervals[i].end = newInterval.end;
		break;
	}

	res = NULL;
	p = 0;
	next = 0;
	while (next < intervalsSize) {
		newInterval.start = intervals[next].start;
		newInterval.end = intervals[next].end;
		for (i = next + 1; i < intervalsSize; i++) {
			if (intervals[i].start > newInterval.end)
				break;
			if (intervals[i].end > newInterval.end)
				newInterval.end = intervals[i].end;
		}
		addans(&newInterval);
		next = i;
	}
	*returnSize = p;
	return(res);
}

int main(void)
{
}
