import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        if (root == null)
            return res;
        LinkedList<TreeNode> q1 = new LinkedList<>();
        LinkedList<TreeNode> q2 = null;
        TreeNode last = null;
        q1.addFirst(root);
        while (q1.size() != 0) {
            q2 = new LinkedList<>();
            while (q1.size() != 0) {
                last = q1.removeLast();
                if (last.left != null)
                    q2.addFirst(last.left);
                if (last.right != null)
                    q2.addFirst(last.right);
            }
            res.add(last.val);
            q1 = q2;
        }
        return res;
    }
}
