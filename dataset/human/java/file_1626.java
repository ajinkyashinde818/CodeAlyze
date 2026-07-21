import java.util.*;

public class Main {

    static final long MOD = 1_000_000_007L;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] s = sc.next().toCharArray();
        long[] c = new long[26];
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            c[idx]++;
        }
        long ans = 1L;
        for (int i = 0; i < 26; i++) {
            ans = (ans * (c[i]+1)) % MOD;
        }
        System.out.println((ans + MOD -1) % MOD);
        sc.close();

    }

}
