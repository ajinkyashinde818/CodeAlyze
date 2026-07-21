import java.util.*;

public class Main {

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int S = sc.nextInt();
        int ans = 0;
        for (int i = 0; i <= K; i++) {
            for (int j = 0; j <= K; j++) {
                if (i + j <= S && S - (i + j) <= K) {
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }
}
