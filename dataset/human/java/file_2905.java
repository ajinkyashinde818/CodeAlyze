import java.util.Scanner;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        boolean[] v1 = new boolean[N];
        boolean[] v2 = new boolean[N];
        Arrays.fill(v1, false);
        Arrays.fill(v2, false);
        for (int i = 0; i < M; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (a == 1) {
                v1[b] = true;
            }
            if (b == N) {
                v2[a] = true;
            }
        }
        for (int i = 1; i < N; i++) {
            if (v1[i] && v2[i]) {
                System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
