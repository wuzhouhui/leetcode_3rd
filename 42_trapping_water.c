int trap(int *height, int heightSize)
{
	if (heightSize <= 2)
		return(0);

	int	leftmax[heightSize], rightmax[heightSize];
	int	i, t, sum;

	t = leftmax[0] = height[0];
	for (i = 1; i < heightSize; i++) {
		leftmax[i] = t;
		if (height[i] > t)
			t = height[i];
	}
	t = rightmax[heightSize - 1] = height[heightSize - 1];
	for (i = heightSize - 2; i >= 0; i--) {
		rightmax[i] = t;
		if (height[i] > t)
			t = height[i];
	}

	sum = 0;
	for (i = 0; i < heightSize; i++) {
		t = (leftmax[i] < rightmax[i] ? leftmax[i] : rightmax[i]);
		if ((t -= height[i]) > 0)
			sum += t;
	}
	return(sum);
}

#include <stdio.h>

int main(void)
{
	int	h[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1, };
	printf("%d\n", trap(h, sizeof(h) / sizeof(h[0])));
}
