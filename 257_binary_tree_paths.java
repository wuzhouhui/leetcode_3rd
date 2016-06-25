import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    private List<String> res;
    private StringBuffer str;
    private void do_path(TreeNode root) {
        if (root == null)
            return;
        int start = str.length();
        if (str.length() == 0)
            str.append(root.val);
        else
            str.append("->" + root.val);
        if (root.left == null && root.right == null)
            res.add(str.toString());
        else {
            do_path(root.left);
            do_path(root.right);
        }
        str.delete(start, str.length());
    }
    public List<String> binaryTreePaths(TreeNode root) {
        res = new LinkedList<>();
        str = new StringBuffer();
        do_path(root);
        return res;
    }
}
