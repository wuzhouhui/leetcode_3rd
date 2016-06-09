import java.util.*;

class MinStack {
    private Stack<Integer> stack;
    private Stack<Integer> minstack;

    public MinStack() {
        stack = new Stack<Integer>();
        minstack = new Stack<Integer>();
    }

    public void push(int x) {
        if (minstack.empty() || x <= minstack.peek())
            minstack.push(x);
        stack.push(x);
    }

    public void pop() {
        int x = stack.pop();
        if (x == minstack.peek())
            minstack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return minstack.peek();
    }
}
