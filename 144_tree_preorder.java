import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    private List<Integer> res;
    private void do_trav(TreeNode root) {
        if (root == null)
            return;
        res.add(root.val);
        do_trav(root.left);
        do_trav(root.right);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        res = new LinkedList<Integer>();
        do_trav(root);
        return res;
    }
}
