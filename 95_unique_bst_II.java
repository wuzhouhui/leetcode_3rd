import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public List<TreeNode> generateTrees(int n) {
        if (n <= 0)
            return new LinkedList<TreeNode>();
        return do_gen(1, n);
    }
   
    private List<TreeNode> do_gen(int start, int end) {
        List<TreeNode> list = new LinkedList<>();
        if (start > end) {
            list.add(null);
            return list;
        }
        for (int i = start; i <= end; i++) {
            List<TreeNode> l1 = do_gen(start, i - 1);
            List<TreeNode> l2 = do_gen(i + 1, end);
            for (int j = 0; j < l1.size(); j++) {
                for (int k = 0; k < l2.size(); k++) {
                    TreeNode node = new TreeNode(i);
                    node.left = l1.get(j);
                    node.right = l2.get(k);
                    list.add(node);
                }
            }
        }
        return list;
    }
}
