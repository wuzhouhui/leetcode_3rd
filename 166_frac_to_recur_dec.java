import java.util.*;

class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0)
            return "";
        if (numerator == 0)
            return "0";
        StringBuffer res = new StringBuffer();
        if ((numerator < 0) ^ (denominator < 0))
            res.append("-");
        long ln = Math.abs((long)numerator);
        long ld = Math.abs((long)denominator);
        long r = (ln % ld) * 10;
        ln /= ld;
        res.append(ln);
        if (r == 0)
            return res.toString();
        res.append(".");
        Map<Long, Integer> map = new HashMap<>();
        while (r != 0) {
            if (map.containsKey(r)) {
                int start = map.get(r);
                String s1 = res.substring(0, start);
                String s2 = res.substring(start);
                return s1 + "(" + s2 + ")";
            }
            map.put(r, res.length());
            res.append(r / ld);
            r = (r % ld) * 10;
        }
        return res.toString();
    }
}
