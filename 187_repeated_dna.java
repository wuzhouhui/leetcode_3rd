import java.util.*;

class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> res = new LinkedList<>();
        int dna = 0;
        HashSet<Integer> set1 = new HashSet<>();
        HashSet<Integer> set2 = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case 'A': dna = (dna << 2) + 0; break;
                case 'T': dna = (dna << 2) + 1; break;
                case 'C': dna = (dna << 2) + 2; break;
                case 'G': dna = (dna << 2) + 3; break;
            }
            if (i < 9)
                continue;
            dna &= (1 << 20) - 1;
            if (set1.contains(dna) && !set2.contains(dna)) {
                set2.add(dna);
                res.add(s.substring(i - 9, i + 1));
            } else
                set1.add(dna);
        }
        return res;
    }
}
