#include <stdlib.h>

struct NumArray {
	int *nums;
	void *data;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
	struct NumArray *numarr = malloc(sizeof(*numarr));
	int i;
	if (numsSize == 0) {
		numarr->data = numarr->nums = NULL;
		return(numarr);
	}
	numarr->data = calloc(numsSize + 1, sizeof(*nums));
	numarr->nums = &((int *)numarr->data)[1];
	for (i = 0; i < numsSize; i++)
		numarr->nums[i] = numarr->nums[i - 1] + nums[i];
	return(numarr);
}

int sumRange(struct NumArray* numArray, int i, int j) {
	return(numArray->nums[j] - numArray->nums[i - 1]);
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
	free(numArray->data);
	free(numArray);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);
main(){}
