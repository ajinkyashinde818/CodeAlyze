import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
    	
        Scanner in = new Scanner(System.in);
        long m = in.nextLong();
        long n = in.nextLong();
        System.out.print(lcm(m, n));
    }
    
    private static long gcd(long m, long n) {
        if(m < n) return gcd(n, m);
        if(n == 0) return m;
        return gcd(n, m % n);
    }
    
    private static long lcm(long m, long n) {
        return m * n / gcd(m, n);
    }
}
