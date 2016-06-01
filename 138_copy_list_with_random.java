import java.util.*;

class RandomListNode {
    int label;
    RandomListNode next, random;
    RandomListNode(int x) { label = x; }
}

class Solution {
    private Map<RandomListNode, RandomListNode> accessed = new HashMap<>();
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null)
            return null;
        if (accessed.containsKey(head))
            return accessed.get(head);
        RandomListNode node = new RandomListNode(head.label);
        accessed.put(head, node);
        node.next = copyRandomList(head.next);
        node.random = copyRandomList(head.random);
        return node;
    }
}
