import java.util.*;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap<>();
        int left = 0, right = 0;
        int max = 0;
        int t = 0;
        while (right < s.length()) {
            Integer c = map.get(s.charAt(right));
            if (c == null || c == 0) {
                map.put(s.charAt(right), 1);
                right++;
                continue;
            }
            t = right - left;
            if (t > max)
                max = t;
            /* c == 1 */
            map.put(s.charAt(right), 2);
            while (left < right) {
                c = map.get(s.charAt(left));
                if (c == 1) {
                    map.put(s.charAt(left), 0);
                    left++;
                    continue;
                }
                map.put(s.charAt(left), 1);
                left++;
                break;
            }
            right++;
        }
        if (left < right)
            t = right - left;
        if (t > max)
            max = t;
        return max;
    }
    public static void main(String[] args) {
        System.out.println(new Solution().lengthOfLongestSubstring(args[0]));
    }
}
