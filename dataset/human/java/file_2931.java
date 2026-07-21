import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = scan.nextInt();
        int M = scan.nextInt();
        HashMap<Integer, List<Integer>> edges = new HashMap<>();
        for (int i = 0; i < M; i++) {
            int from = scan.nextInt() - 1;
            int to = scan.nextInt() - 1;
            if (!edges.containsKey(from)) {
                edges.put(from, new ArrayList<>());
            }
            edges.get(from).add(to);
        }
        List<Integer> firstlist = edges.get(0);
        boolean answer = false;
        for (int first : firstlist) {
            List<Integer> secondlist = edges.get(first);
            if (secondlist == null) {
                continue;
            }
            for (int second : secondlist) {
                if (second == N - 1) {
                    answer = true;
                    break;
                }
            }
        }
        System.out.println(answer ? "POSSIBLE" : "IMPOSSIBLE");
    }
}
