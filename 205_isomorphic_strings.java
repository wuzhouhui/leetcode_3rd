import java.util.*;

class Solution {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character, Character> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (map.containsKey(c)) {
                c = map.get(c);
                if (c != t.charAt(i))
                    return false;
            } else {
                map.put(c, t.charAt(i));
            }
        }

        map.clear();
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            if (map.containsKey(c)) {
                c = map.get(c);
                if (c != s.charAt(i))
                    return false;
            } else {
                map.put(c, s.charAt(i));
            }
        }
        return true;
    }
}
