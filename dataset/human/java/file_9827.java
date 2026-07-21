import java.util.*;

public class Main {

    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int m = sc.nextInt();
    int x = sc.nextInt();
    int[][] arr = new int[n][m+1];
    int ans = Integer.MAX_VALUE;


    public static void main(String[] args) {
        new Main().run();
    }

    void run() {

        for (int i=0; i<n; i++) {
            for (int j=0; j<m+1; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        dfs("0");
        dfs("1");

        if (ans == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }

    }

    void dfs(String s) {
        if (s.length() == n) {
            ans = Math.min(ans, calc(s));
//            System.out.println(s);
        }
        if (s.length() <= n) {
            for (int i=0; i<2; i++) {
                s = s + String.valueOf(i);
                dfs(s);
                s = s.substring(0, s.length()-1);
            }
        }
    }

    int calc(String s) {
        int ret = 0;
        int[] p = new int[m];
        for (int i=0; i<n; i++) {
            if (s.charAt(i) == '1') {
                for (int j=0; j<m; j++) {
                    p[j] += arr[i][j+1];
                }
                ret += arr[i][0];
            }
        }
        for (int i=0; i<m; i++) {
            if (p[i] < x) {
                return Integer.MAX_VALUE;
            }
        }
        return ret;
    }
}
