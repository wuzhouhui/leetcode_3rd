import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    private List<List<Integer>> res;
    private List<Integer> path;
    private void do_sum(TreeNode root, int cur, int sum) {
        if (root == null)
            return;
        cur += root.val;
        path.add(root.val);
        if (root.left == null && root.right == null && cur == sum) {
            List<Integer> t = new LinkedList<>();
            t.addAll(path);
            res.add(t);
        }
        do_sum(root.left, cur, sum);
        do_sum(root.right, cur, sum);
        path.remove(path.size() - 1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        res = new LinkedList<>();
        path = new LinkedList<>();
        do_sum(root, 0, sum);
        return res;
    }
}
