import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    private boolean ancestor(TreeNode root, TreeNode p,
            LinkedList<TreeNode> l) {
        if (root == null)
            return false;
        l.addLast(root);
        if (root == p)
            return true;
        if (ancestor(root.left, p, l) == true)
            return true;
        if (ancestor(root.right, p, l) == true)
            return true;
        l.removeLast();
        return false;
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p,
            TreeNode q) {
        LinkedList<TreeNode> l1 = new LinkedList<>();
        LinkedList<TreeNode> l2 = new LinkedList<>();
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
