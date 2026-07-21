import java.util.*;

public class Main {
    static long MOD = 1000000007;
    
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = 26;
        int m = sc.nextInt();
        String str = sc.next();
        char[] c = str.toCharArray();
        
        long[] alphabet = new long[n];
        for (int i = 0; i < c.length; i++) {
            int idx = c[i] - 'a';
            alphabet[idx]++;
        }
        
        long ans = 1;
        for (int i = 0; i < 26; i++) {
            ans *= (alphabet[i] + 1);
            ans %= MOD;
        }
        ans--;
        if (ans < 0) ans += MOD;
        System.out.println(ans);
    }
}
