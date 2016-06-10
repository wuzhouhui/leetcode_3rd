static void reverse(int *nums, int l, int r)
{
	int t;
	while (l < r) {
		t = nums[l];
		nums[l] = nums[r];
		nums[r] = t;
		l++, r--;
	}
}
void rotate(int *nums, int numsSize, int k)
{
	if (numsSize <= 1 || (k %= numsSize) == 0)
		return;
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
}

int main(void)
{
}
