import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    private void ancestor(TreeNode root, TreeNode p, List<TreeNode> l) {
        if (root == null)
            return;
        l.add(root);
        if (root.val == p.val)
            return;
        else if (root.val > p.val)
            ancestor(root.left, p, l);
        else
            ancestor(root.right, p, l);
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p,
            TreeNode q) {
        List<TreeNode> l1 = new LinkedList<>();
        List<TreeNode> l2 = new LinkedList<>();
        ancestor(root, p, l1);
        ancestor(root, q, l2);
        TreeNode res = null;
        for (int i = 0; i < l1.size() && i < l2.size(); i++) {
            if (l1.get(i) == l2.get(i))
                res = l1.get(i);
            else
                break;
        }
        return res;
    }
}
