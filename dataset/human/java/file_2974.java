import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        List<Integer>[] islands = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            islands[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            islands[a].add(b);
            islands[b].add(a);
        }
        
        for (List<Integer> island : islands) {
            if (island.contains(0) && island.contains(n - 1)) {
                System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
