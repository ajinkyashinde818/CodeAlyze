import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static List<List<Integer>> graph;
    static boolean[] seen;
    static int[] depth;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String res = "IMPOSSIBLE";
        graph = new ArrayList<>();
        Queue<Integer> que = new ArrayDeque<>();
        int n = sc.nextInt(), m = sc.nextInt();
        seen = new boolean[n];
        depth = new int[n];
        for(int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for(int i = 0; i < m; i++) {
            int a = Integer.parseInt(sc.next())-1, b = Integer.parseInt(sc.next())-1;
            graph.get(a).add(b);
            graph.get(b).add(a);
        }
        int v = 0;
        que.offer(0);
        depth[0] = 0;
        while(que.size() > 0 && depth[v] < 2) {
            v = que.poll();
            for(int a : graph.get(v)) {
                if(a == n-1) res = "POSSIBLE";
                if(seen[a]) continue;
                que.offer(a);
                depth[a] = depth[v] + 1;
                seen[a] = true;
            }
        }
        System.out.println(res);
    }
}
