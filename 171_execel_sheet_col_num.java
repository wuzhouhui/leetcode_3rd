class Solution {
    public int titleToNumber(String s) {
        int res = 0, pow = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            res += (s.charAt(i) + 1 - 'A') * pow;
            pow *= 26;
        }
        return res;
    }
}
