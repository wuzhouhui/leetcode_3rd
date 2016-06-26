// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
import java.util.*;
class PeekingIterator implements Iterator<Integer> {
    private Integer n;
    private Iterator<Integer> ite;
    public PeekingIterator(Iterator<Integer> iterator) {
        // initialize any member here.
        ite = iterator;
        if (ite.hasNext())
            n = ite.next();
        else
            n = null;
    }

    // Returns the next element in the iteration without advancing the iterator.
    public Integer peek() {
        return n;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    @Override
    public Integer next() {
        Integer r = n;
        if (ite.hasNext())
            n = ite.next();
        else
            n = null;
        return r;
    }

    @Override
    public boolean hasNext() {
        return n != null;
    }
}
