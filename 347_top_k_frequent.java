import java.util.*;

class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        if (nums.length <= 0 || k <= 0)
            return new ArrayList<Integer>();

        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            Integer c = map.get(nums[i]);
            if (c == null)
                c = 0;
            else
                c++;
            map.put(nums[i], c);
        }
        PriorityQueue<Map.Entry<Integer, Integer>> heap = new
            PriorityQueue<>(k, new MyComp());
        Iterator<Map.Entry<Integer, Integer>> ite = map.entrySet().iterator();
        while (ite.hasNext()) {
            Map.Entry<Integer, Integer> pair = ite.next();
            heap.offer(pair);
            if (heap.size() > k)
                heap.poll();
        }
        List<Integer> res = new ArrayList<>(k);
        ite = heap.iterator();
        while (ite.hasNext())
            res.add(ite.next().getKey());
        return res;
    }

    private class MyComp implements Comparator<Map.Entry<Integer, Integer>> {
        public int compare(Map.Entry<Integer, Integer> a,
                Map.Entry<Integer, Integer> b) {
            return a.getValue() - b.getValue();
        }
    }
}
