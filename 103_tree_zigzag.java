import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        LinkedList<TreeNode> q1 = new LinkedList<TreeNode>();
        LinkedList<TreeNode> q2 = null;
        if (root != null)
            q1.add(root);
        boolean flag = true;
        List<List<Integer>> res = new LinkedList<>();
        while (q1.peek() != null) {
            q2 = q1;
            q1 = new LinkedList<TreeNode>();
            List<Integer> t = new LinkedList<Integer>();
            while (q2.peek() != null) {
                TreeNode node = q2.poll();
                if (flag) {
                    if (node.left != null)
                        q1.addFirst(node.left);
                    if (node.right != null)
                        q1.addFirst(node.right);
                } else {
                    if (node.right != null)
                        q1.addFirst(node.right);
                    if (node.left != null)
                        q1.addFirst(node.left);
                }
                t.add(node.val);
            }
            res.add(t);
            flag = !flag;
        }
        return res;
    }
}
