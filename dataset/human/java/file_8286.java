import java.util.*;

public class Main {
    static int MOD = 1000000007;
	static int INF = Integer.MAX_VALUE;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        sc.close();
        long res = lcm(a, b);
        
        System.out.println(res);
    }
    // GCD
    public static int gcd(int m, int n) {
        if(m < n) return gcd(n, m);
        if(n == 0) return m;
        return gcd(n, m % n);
    }
    // LCM
    public static long lcm(int a, int b) {
		int d = gcd(a, b);
        return (long)a / d * b;
    }
}
