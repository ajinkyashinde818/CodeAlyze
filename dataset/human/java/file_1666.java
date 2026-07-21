import java.util.*;

public class Main {
    static final long MOD = 1000000007;
    static final int ALN = 26;
    static Scanner sc = new Scanner(System.in);
    
    public static void main(String[] args) {
        int n = sc.nextInt();
        String s = sc.next();
        long[] appearance = new long[ALN];
        for(int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            int windex = (int)(c - 'a');
            ++appearance[windex];
        }
        long ans = 1;
        for(int i = 0; i < ALN; ++i) {
            ans *= appearance[i] + 1;
            ans %= MOD;
        }
        --ans;
        System.out.println(ans);
    }
}
