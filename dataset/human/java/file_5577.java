import java.util.*;
 
public class Main {

    private static int MOD = 1_000_000_007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int S = sc.nextInt();

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < K; i++) {
            ans.append(S).append(" ");
        }
        if (S < 1_000_000_000) {
            for (int i = K; i < N; i++) {
                ans.append(S+1).append(" ");
            }
        } else {
            for (int i = K; i < N; i++) {
                ans.append(1).append(" ");
            }
        }

        System.out.println(ans.toString());
    }
}
