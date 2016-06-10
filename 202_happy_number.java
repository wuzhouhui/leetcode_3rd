import java.util.*;

class Solution {
    private int[] square = new int[] { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 };
    public boolean isHappy(int n) {
        HashSet<Integer> set = new HashSet<>();
        int r;
        while (true) {
            r = 0;
            do {
                r += square[n % 10];
                n /= 10;
            } while (n != 0);
            if (r == 1)
                return true;
            if (set.contains(r))
                return false;
            set.add(r);
            n = r;
        }
    }
}
