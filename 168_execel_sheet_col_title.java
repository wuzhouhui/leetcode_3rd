class Solution {
    public String convertToTitle(int n) {
        StringBuilder res = new StringBuilder();
        int r = 0;
        while (n > 0) {
            r = n % 26;
            n /= 26;
            if (r == 0) {
                r = 26;
                n--;
            }
            res.append((char)('A' + r - 1));
        }
        return res.reverse().toString();
    }
}
