import java.util.*;
import java.math.*;
class Main {
    //
    static final long MOD = 1_000_000_007; // 10^9+7
    //static final int MAX = 2_147_483_646; // intの最大値
    
    static final int INF = 1_000_000_000; // 10^9
    static final int MAX = 10_000_000;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        if(n >= 10){
            System.out.println(m);
        }else{
            System.out.println(m + 100*(10-n));
        }
    }
    

    
}
