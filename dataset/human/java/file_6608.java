import java.util.*;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        String[] s = scanner.next().split("T");
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        List<Integer> xList = new ArrayList<>();
        List<Integer> yList = new ArrayList<>();
        int i = 0;
        for (String t : s) {
            if (i++ % 2 == 0) {
                xList.add(t.length());
            } else {
                yList.add(t.length());
            }
        }

        if (x < 0 && xList.stream().mapToInt(Integer::intValue).sum() <= -x && xList.get(0) != 0) {
            System.out.println("No");
        } else {
            System.out.println(f(xList.toArray(new Integer[0]), x) && f(yList.toArray(new Integer[0]), y) ? "Yes" : "No");
        }
    }

    static boolean f(Integer[] a, int n) {
        boolean[][] dp = new boolean[a.length + 1][18000];
        dp[0][9000] = true;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < 18000; j++) {
                if (0 <= j - a[i]) {
                    dp[i + 1][j] |= dp[i][j - a[i]];
                }
                if (18000 > j + a[i]) {
                    dp[i + 1][j] |= dp[i][j + a[i]];
                }
            }
        }
        return dp[a.length][n + 9000];
    }
}
