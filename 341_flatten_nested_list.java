/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested queue.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested queue
 *     public Integer getInteger();
 *
 *     // @return the nested queue that this NestedInteger holds, if it holds a nested queue
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
import java.util.*;

public class NestedIterator implements Iterator<Integer> {
    private LinkedList<Integer> queue;
    private void do_flatten(NestedInteger ni) {
        if (ni.isInteger()) {
            queue.addLast(ni.getInteger());
            return;
        }
        for (int i = 0; i < ni.getList().size(); i++)
            do_flatten(ni.getList().get(i));
    }
    public NestedIterator(List<NestedInteger> nestedList) {
        queue = new LinkedList<>();
        for (int i = 0; i < nestedList.size(); i++)
            do_flatten(nestedList.get(i));
    }

    @Override
    public Integer next() {
        return queue.removeFirst();
    }

    @Override
    public boolean hasNext() {
        return queue.size() != 0;
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */
