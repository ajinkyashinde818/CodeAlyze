import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        List<Integer[]> edgeList = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int a = Integer.parseInt(sc.next());
            int b = Integer.parseInt(sc.next());
            edgeList.add(new Integer[] { a, b });
        }
        sc.close();

        // 主処理
        Map<Integer, HashSet<Integer>> graph = createGraph(n, edgeList, false);
        int start = 1;
        int target = n;
        int distance = getDistance(n + 1, graph, start, target);

        boolean judge = distance != 0 && distance <= 2;
        String result = judge ? "POSSIBLE" : "IMPOSSIBLE";

        // 出力
        System.out.println(result);
    }

    // グラフを作成
    public static Map<Integer, HashSet<Integer>> createGraph(int nodeSize, List<Integer[]> edgeList,
            boolean isDirected) {
        Map<Integer, HashSet<Integer>> graph = new HashMap<>();
        for (int i = 1; i <= nodeSize; i++) {
            graph.put(i, new HashSet<>());
        }
        if (isDirected) {
            for (Integer[] edge : edgeList) {
                graph.get(edge[0]).add(edge[1]);
            }
        } else {
            for (Integer[] edge : edgeList) {
                graph.get(edge[0]).add(edge[1]);
                graph.get(edge[1]).add(edge[0]);
            }
        }
        return graph;
    }

    // 最短距離を求める
    public static int getDistance(int nodeSize, Map<Integer, HashSet<Integer>> graph, int start, int target) {
        Deque<Integer> deque = new ArrayDeque<>();
        deque.add(start);

        int[] distance = new int[nodeSize];
        distance[start]++;

        int dist = 0;
        while (!deque.isEmpty()) {
            int point = deque.poll();
            if (point == target) {
                dist = distance[point] - 1;
                break;
            }
            for (int nextPoint : graph.get(point)) {
                if (distance[nextPoint] == 0) {
                    deque.add(nextPoint);
                    distance[nextPoint] = distance[point] + 1;
                }
            }
        }

        return dist;
    }
}
