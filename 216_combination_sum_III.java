import java.util.*;

class Solution {
    private LinkedList<List<Integer>> res;
    private LinkedList<Integer> buf;
    private void do_sum(int start, int len, int sum, int cur) {
        if (buf.size() == len && cur == sum) {
            res.add(new LinkedList<>(buf));
            return;
        } else if (buf.size() > len || cur > sum || start > 9)
            return;

        for (int i = start; i <= 9; i++) {
            cur += i;
            if (cur > sum)
                return;
            buf.addLast(i);
            do_sum(i + 1, len, sum, cur);
            buf.removeLast();
            cur -= i;
        }
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        res = new LinkedList<>();
        buf = new LinkedList<>();
        do_sum(1, k, n, 0);
        return(res);
    }
}
