class Solution {
    public int majorityElement(int[] nums) {
        int c = 1, k = nums[0];
        for (int i = 1; i < nums.length; i++)
            if (nums[i] != k) {
                if (--c == 0) {
                    c = 1;
                    k = nums[i];
                }
            } else
                c++;
        return k;
    }
}
