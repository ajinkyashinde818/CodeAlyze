import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }

    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int K = scan.nextInt();
        int N = scan.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scan.nextInt();
        }
        long ans = Long.MAX_VALUE;
        for (int i = 0; i < N; i++) {
            ans = Math.min(ans, tokei(N, K, A, i));
            ans = Math.min(ans, reverse(N, K, A, i));
        }
        System.out.println(ans);
    }
    private long tokei(int N, int K, int[] A, int start) {
        if (start == 0) {
            return A[N-1] - A[0];
        }
        return K - A[start] + A[start-1];
    }
    private long reverse(int N, int K, int[] A, int start) {
        if (start == N-1) {
            return A[N-1] - A[0];
        }
        return A[start] + K - A[start+1];
    }
}
