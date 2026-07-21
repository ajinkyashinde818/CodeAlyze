import java.util.*;
import java.math.*;
public class Main {
    static final int MOD = 1_000_000_007; // 10^9+7
    //static final int MAX = 2_147_483_646; // intの最大値
    static final int INF = 1_000_000_000; // 10^9
    static final int MAX = 10_000_000;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] ary = new int[n];
        for(int i = 0;i < n;i++){
            ary[i] = sc.nextInt();
        }
        int[] l = new int[n];
        l[0] = ary[n-1]-ary[0];
        for(int i = 1;i < n;i++){
            l[i] = ary[i-1]-ary[i]+k;
        }
        Arrays.sort(l);
        System.out.println(l[0]);

    }       
}
