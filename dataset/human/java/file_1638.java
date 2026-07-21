import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        final long MOD = 1_000_000_007L;
        int[] alpha = new int[26];
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            alpha[c - 'a']++;
        }
        long ans = 1;
        for (int i = 0; i < alpha.length; i++) {
            ans *= alpha[i] + 1;
            ans %= MOD;
        }
        System.out.println((ans + MOD - 1) % MOD);
    }
}
