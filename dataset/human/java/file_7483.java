import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int N = S.length();
        String[] words = {
            "dream",
            "dreamer",
            "erase",
            "eraser"
        };
        boolean[] dp = new boolean[N+1];
        dp[0] = true;
        for (int i = 0; i < N; i++) {
            if (dp[i]) {
                for (String w : words) {
                    if (S.startsWith(w, i)) {
                        dp[i + w.length()] = true;
                    }
                }
            }
        }
        System.out.println(dp[N] ? "YES" : "NO");
        
    }
}
