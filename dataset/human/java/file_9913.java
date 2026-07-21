import java.util.Scanner;

public class Main {

    static int test(int n, int m, int x, int[][] A, int mask) {
        int[] s = new int[m];
        int cost = 0;
        for (int i=0;i<n;i++) {
            if ((mask & (1<<i)) != 0) {
                cost += A[i][0];
                for (int j=1;j<=m;j++) s[j-1] += A[i][j];
            }
        }

        for (int i=0;i<m;i++) if (s[i] < x) return -1;
        return cost;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = in.nextInt(), x = in.nextInt();
        int[][] A = new int[n][m+1];
        for (int i=0;i<n;i++) {
            A[i][0] = in.nextInt();
            for (int j=1;j<=m;j++) A[i][j] = in.nextInt();
        }

        int ret = -1;
        for (int i=0;i<(1<<12);i++) {
            int t = test(n, m, x, A, i);
            if (t != -1) {
                if (ret == -1 || t < ret) ret = t;
            }
        }

        System.out.println(ret);
    }
}
