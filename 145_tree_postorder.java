import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    private List<Integer> res;
    private void do_postorder(TreeNode root) {
        if (root == null)
            return;
        do_postorder(root.left);
        do_postorder(root.right);
        res.add(root.val);
    }
    public List<Integer> postorderTraversal(TreeNode root) {
        res = new LinkedList<Integer>();
        do_postorder(root);
        return res;
    }
}
