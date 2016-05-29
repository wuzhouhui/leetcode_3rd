import java.util.*;

class UndirectedGraphNode {
    int label;
    List<UndirectedGraphNode> neighbors;
    UndirectedGraphNode(int x) {
        label = x;
        neighbors = new ArrayList<UndirectedGraphNode>();
    }
}

class Solution {
    private Map<UndirectedGraphNode, UndirectedGraphNode> accessed =
        new HashMap<>();
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (node == null || accessed.containsKey(node))
            return null;
        UndirectedGraphNode g = new UndirectedGraphNode(node.label);
        accessed.put(node, g);
        for (int i = 0; i < node.neighbors.size(); i++) {
            if (accessed.containsKey(node.neighbors.get(i))) {
                g.neighbors.add(accessed.get(node.neighbors.get(i)));
                continue;
            }
            g.neighbors.add(cloneGraph(node.neighbors.get(i)));
        }
        return g;
    }
}
