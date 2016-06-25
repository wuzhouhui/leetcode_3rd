import java.util.*;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (k < 1)
            return new int[0];

        int[] res = new int[nums.length - k + 1];
        int rp = 0;
        Deque<Integer> dq = new ArrayDeque<>(k);
        for (int i = 0; i < nums.length; i++) {
            while (!dq.isEmpty() && dq.peek() < i + 1 - k)
                dq.poll();
            while (!dq.isEmpty() && nums[dq.peekLast()] <= nums[i])
                dq.pollLast();
            dq.offer(i);
            if (i >= k - 1)
                res[rp++] = nums[dq.peek()];
        }
        return res;
    }
}
