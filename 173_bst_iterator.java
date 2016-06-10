import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class BSTIterator {
    private Stack<TreeNode> stack;

    private void pushAllLeft(TreeNode node) {
        while (node != null) {
            stack.push(node);
            node = node.left;
        }
    }

    public BSTIterator(TreeNode node) {
        stack = new Stack<>();
        pushAllLeft(node);
    }

    public boolean hasNext() {
        return !stack.empty();
    }

    public int next() {
        TreeNode node = stack.pop();
        pushAllLeft(node.right);
        return node.val;
    }
}
