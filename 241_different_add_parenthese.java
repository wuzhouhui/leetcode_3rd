import java.util.*;

class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> res = new LinkedList<>();
        for (int i = 0; i < input.length(); i++) {
            if (input.charAt(i) != '+' && input.charAt(i) != '-'
                    && input.charAt(i) != '*')
                continue;
            List<Integer> left =
                diffWaysToCompute(input.substring(0, i));
            List<Integer> right =
                diffWaysToCompute(input.substring(i + 1));
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    int t = 0;
                    switch (input.charAt(i)) {
                        case '+':
                            t = left.get(j) + right.get(k);
                            break;
                        case '-':
                            t = left.get(j) - right.get(k);
                            break;
                        case '*':
                            t = left.get(j) * right.get(k);
                            break;
                    }
                    res.add(t);
                }
            }
        }
        if (res.size() == 0)
            res.add(Integer.parseInt(input));
        return res;
    }
}
