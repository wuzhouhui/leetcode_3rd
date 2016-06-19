import java.util.*;

class MyStack {
    private LinkedList <Integer> queue1 = new LinkedList<>();
    private LinkedList <Integer> queue2 = new LinkedList<>();
    // Push element x onto stack.
    public void push(int x) {
        if (queue1.size() != 0)
            queue1.offer(x);
        else
            queue2.offer(x);
    }

    // Removes the element on top of the stack.
    public void pop() {
        if (queue1.size() != 0) {
            while (queue1.size() != 1)
                queue2.offer(queue1.poll());
            queue1.poll();
        } else {
            while (queue2.size() != 1)
                queue1.offer(queue2.poll());
            queue2.poll();
        }
    }

    // Get the top element.
    public int top() {
        int t = 0;
        if (queue1.size() != 0) {
            while (queue1.size() != 1)
                queue2.offer(queue1.poll());
            t = queue1.peek();
            queue2.offer(queue1.poll());
            return t;
        } else {
            while (queue2.size() != 1)
                queue1.offer(queue2.poll());
            t = queue2.peek();
            queue1.offer(queue2.poll());
            return t;
        }
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return queue1.size() == 0 && queue2.size() == 0;
    }
}
