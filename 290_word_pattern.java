import java.util.*;

class Solution {
    public boolean wordPattern(String pattern, String str) {
        Map<Character, String> chmap = new HashMap<>();
        String[] strs = str.split(" ");
        if (pattern.length() != strs.length)
            return false;
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern.charAt(i);
            String s = chmap.get(c);
            if (s == null) {
                s = strs[i];
                chmap.put(c, s);
            }
            if (s.equals(strs[i]) == false)
                return false;
        }
        Map<String, Character> strmap = new HashMap<>();
        for (int i = 0; i < strs.length; i++) {
            String s = strs[i];
            Character c = strmap.get(s);
            if (c == null) {
                c = pattern.charAt(i);
                strmap.put(s, c);
            }
            if (c != pattern.charAt(i))
                return false;
        }
        return true;
    }
}
