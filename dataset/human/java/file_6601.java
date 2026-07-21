import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            String s = in.next();
            int x = in.nextInt();
            int y = in.nextInt();

            String[] move = s.split("T");
            List<Integer> yoko = new ArrayList<>();
            List<Integer> tate = new ArrayList<>();
            for (int i = 0; i < move.length; i++) {
                if (i % 2 == 0) {
                    yoko.add(move[i].length());
                } else {
                    tate.add(move[i].length());
                }
            }
            int start = 0;
            if (yoko.size() > 0) {
                start = yoko.remove(0);
            }
            boolean endInX = new DFS(yoko, start, x).solve();
            boolean endInY = new DFS(tate, 0, y).solve();
            String ans = (endInX && endInY)
                    ? "Yes" : "No";
            System.out.println(ans);
        }
    }

    private static class DFS {
        private final List<Integer> arr;
        private final int goal;
        private final int offset;
        private final boolean[][] dp;

        private DFS(List<Integer> arr, int start, int goal) {
            this.arr = arr;
            this.goal = goal;
            int sum = 0;
            for (int a : arr) {
                sum += a;
            }
            this.offset = 10000;
            this.dp = new boolean[arr.size() + 1][(offset * 2 + start)];
            this.dp[0][offset + start] = true;
        }

        private boolean solve() {
            if (dp[0].length <= offset + goal) {
                return false;
            }
            for (int i = 0; i < arr.size(); i++) {
                for (int j = 0; j < dp[0].length; j++) {
                    if (dp[i][j]) {
                        dp[i + 1][j + arr.get(i)] = true;
                        dp[i + 1][j - arr.get(i)] = true;
                    }
                }
            }
            return dp[arr.size()][offset + goal];
        }
    }
}
