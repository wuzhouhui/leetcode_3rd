#include <string.h>

enum {
	RED = 0,
	WHITE = 1,
	BLUE = 2,
	COLORS,
};

void sortColors(int *nums, int numsSize)
{
	int	colors[COLORS], i;

	memset(colors, 0, sizeof(colors));
	for (i = 0; i < numsSize; i++)
		colors[nums[i]]++;
	i = 0;
	while (colors[RED]--)
		nums[i++] = RED;
	while (colors[WHITE]--)
		nums[i++] = WHITE;
	while (colors[BLUE]--)
		nums[i++] = BLUE;
}

int main(void)
{
}
