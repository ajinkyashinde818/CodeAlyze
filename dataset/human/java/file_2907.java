import java.util.*;

public class Main {
    public static void main(final String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] r = new int[m][2];
        Set<Integer> can1 = new HashSet<>();
        Set<Integer> can2 = new HashSet<>();
        for (int i = 0; i < m; i++) {
            int from = sc.nextInt();
            int to = sc.nextInt();
            if (from == 1) can1.add(to);
            if (to == n) can2.add(from);
        }

        for (int i : can1) {
            if (can2.contains(i)) {
                System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
