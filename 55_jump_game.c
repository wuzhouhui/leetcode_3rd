#ifndef bool
#define bool int
#endif

bool canJump(int *nums, int numsSize)
{
	if (numsSize <= 1)
		return(1);

	int	start, i, next, t, max;

	start = 0;
	while (1) {
		next = start;
		max = 0;
		for (i = 1; i <= nums[start]; i++) {
			if (start + i >= numsSize - 1)
				return(1);
			t = i + nums[start + i];
			if (t > max) {
				max = t;
				next = start + i;
			}
		}
		if (next == start)
			return(0);
		start = next;
	}
}

int main(void)
{
}
