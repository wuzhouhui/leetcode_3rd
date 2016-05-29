import java.util.*;

class Solution {
    private List<List<String>> res;
    private boolean validPal(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j)
            if (s.charAt(i++) != s.charAt(j--))
                return false;
        return true;
    }
    private void do_part(String s, int start, List<String> apart) {
        if (start >= s.length()) {
            List<String> list = new LinkedList<>(apart);
            res.add(list);
            return;
        }
        for (int i = start; i < s.length(); i++) {
            String substr = s.substring(start, i + 1);
            if (validPal(substr)) {
                apart.add(substr);
                do_part(s, i + 1, apart);
                apart.remove(apart.size() - 1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        res = new LinkedList<>();
        List<String> apart = new LinkedList<>();
        if (s.length() > 0)
            do_part(s, 0, apart);
        return res;
    }
}
