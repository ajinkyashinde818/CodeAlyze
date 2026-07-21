import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static final int INF = (int)Math.pow(10, 9) + 7;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int X = sc.nextInt();
        int[] C = new int[N];
        int[][] A = new int[N][M];
        for (int i = 0; i < A.length; i++) {
            C[i] = sc.nextInt();
            for (int j = 0; j < A[i].length; j++) {
                A[i][j] = sc.nextInt();
            }
        }
        boolean ok = false;
        int min = INF;
        for (int bit = 0; bit < (1 << N); bit++) {
            int money = 0;
            int[] understand = new int[M];
            for (int i = 0; i < N; i++) {
                if ((bit & (1 << i)) != 0) {
                    money += C[i];
                    for (int j = 0; j < M; j++) {
                        understand[j] += A[i][j];
                    }
                }
            }
            Arrays.sort(understand);
            if (understand[0] >= X) {
                ok = true;
                min = Math.min(min, money);
            }
        }
        if (ok) {
            System.out.println(min);
        } else {
            System.out.println(-1);
        }
        sc.close();
    }
}
