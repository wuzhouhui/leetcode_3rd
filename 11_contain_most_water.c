int maxArea(int *height, int heightSize)
{
	int	left, right, max, t;

	max = 0;
	left = 0;
	right = heightSize - 1;
	while (left < right) {
		if (height[left] < height[right]) {
			if ((t = height[left] * (right - left)) > max)
				max = t;
			t = height[left];
			while (left < right && height[left] <= t)
				left++;
			continue;
		}
		if ((t = height[right] * (right - left)) > max)
			max = t;
		t = height[right];
		while (left < right && height[right] <= t)
			right--;
	}
	return(max);
}

int main(void)
{
}
