import java.util.*;

class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> res = new LinkedList<>();
        if (nums.length == 0)
            return res;
        int i = 0;
        while (true) {
            int start = nums[i++];
            while (i < nums.length && nums[i] == nums[i - 1] + 1)
                i++;
            int end = nums[i - 1];
            if (start == end)
                res.add("" + start);
            else
                res.add(start + "->" + end);
            if (i >= nums.length)
                break;
        }
        return res;
    }
}
