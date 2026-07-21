import java.util.*;

public class Main implements Runnable {

    private static int MOD = 1_000_000_007;

    public static void main(String[] args) {
        // Run with 32MB stack
        Thread thread = new Thread(null, new Main(), "", 32 * 1024 * 1024);
        thread.start();
    }

    @Override
    public void run() {
        final Scanner scanner = new Scanner(System.in);
        solve(scanner);
    }

    static void solve(Scanner scanner) {
        int V = scanner.nextInt();
        scanner.nextLine();

        Tree tree = new Tree();
        for (int i = 0; i < V - 1; i++) {
            int[] e = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            tree.addEdge(e[0], e[1], e[2]);
            tree.addEdge(e[1], e[0], e[2]);
        }

        tree.computeHeights();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < V; i++) {
            sb.append(tree.heightsFromEach.getOrDefault(i, 0));
            sb.append('\n');
        }
        System.out.print(sb.toString());
    }

}

class Tree {
    public Map<Integer, Set<Edge>> edges;
    public Map<Integer, Integer> heightsFromEach;

    public Tree() {
        edges = new HashMap<>();
        heightsFromEach = new HashMap<>();
    }

    public void addEdge(int from, int to) {
        addEdge(from, to, 1);
    }

    public void addEdge(int from, int to, int cost) {
        if (!edges.containsKey(from)) {
            edges.put(from, new HashSet<>());
        }
        edges.get(from).add(new Edge(from, to, cost));
    }

    public int getDiameter() {
        int randomNode = edges.keySet().stream().findAny().orElse(-1);
        if (randomNode == -1) {
            return 0;
        }
        int farthest = getFarthest(randomNode);
        return getOneHeight(farthest);
    }

    public int getOneHeight(int root) {
        return dfs(root, new HashSet<>());
    }

    public void computeHeights() {
        int randomNode = edges.keySet().stream().findAny().orElse(-1);
        if (randomNode == -1) {
            return;
        }
        int edge1 = getFarthest(randomNode);
        int edge2 = getFarthest(edge1);
        Map<Integer, Integer> distFrom1 = getDistFromNode(edge1);
        Map<Integer, Integer> distFrom2 = getDistFromNode(edge2);
        heightsFromEach.putAll(distFrom1);
        for (Map.Entry<Integer, Integer> kv: distFrom2.entrySet()) {
            if (heightsFromEach.getOrDefault(kv.getKey(), 0) < kv.getValue()) {
                heightsFromEach.put(kv.getKey(), kv.getValue());
            }
        }
    }

    private int getFarthest(int node) {
        Queue<NodeCost> q = new PriorityQueue<>(Comparator.comparingInt(x -> x.cost));
        q.add(new NodeCost(node, 0));
        int farthest = node;
        Set<Integer> visited = new HashSet<>();
        while (!q.isEmpty()) {
            NodeCost nc = q.poll();
            if (visited.add(nc.node)) {
                farthest = nc.node;
                for (Edge e : edges.getOrDefault(nc.node, Collections.emptySet())) {
                    q.add(new NodeCost(e.to, nc.cost + e.cost));
                }
            }
        }
        return farthest;
    }

    private Map<Integer, Integer> getDistFromNode(int node) {
        Map<Integer, Integer> dist = new HashMap<>();
        Queue<NodeCost> q = new PriorityQueue<>(Comparator.comparingInt(x -> x.cost));
        q.add(new NodeCost(node, 0));
        Set<Integer> visited = new HashSet<>();
        while (!q.isEmpty()) {
            NodeCost nc = q.poll();
            if (visited.add(nc.node)) {
                dist.put(nc.node, nc.cost);
                for (Edge e : edges.getOrDefault(nc.node, Collections.emptySet())) {
                    q.add(new NodeCost(e.to, nc.cost + e.cost));
                }
            }
        }
        return dist;
    }

    private int dfs(int s, HashSet<Integer> visited) {
        int ans = 0;
        if (visited.add(s)) {
            for (Edge e : edges.getOrDefault(s, Collections.emptySet())) {
                if (visited.contains(e.to)) {
                    continue;
                }
                ans = Math.max(ans, e.cost + dfs(e.to, visited));
            }
        }
        return ans;
    }

}

class Edge {
    public final int from;
    public final int to;
    public final int cost;

    public Edge(int from, int to, int cost) {
        this.from = from;
        this.to = to;
        this.cost = cost;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Edge edge = (Edge) o;
        return from == edge.from &&
                to == edge.to &&
                cost == edge.cost;
    }

    @Override
    public int hashCode() {
        return Objects.hash(from, to, cost);
    }
}

class NodeCost {
    public final int node;
    public final int cost;

    public NodeCost(int node, int cost) {
        this.node = node;
        this.cost = cost;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        NodeCost nodeCost = (NodeCost) o;
        return node == nodeCost.node &&
                cost == nodeCost.cost;
    }

    @Override
    public int hashCode() {
        return Objects.hash(node, cost);
    }
}
