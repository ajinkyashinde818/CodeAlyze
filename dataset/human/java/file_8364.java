import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println(lcm(a,b));
    }
    static long gcd(long m, long n) {
        long r;
        if(m < n) {
            long tmp = m;
            m = n;
            n = tmp;
        }
        while(n > 0) {
            r = m % n;
            m = n;
            n = r;
        }
        return m;
    }
    static long lcm(long m, long n) {
        return m * n / gcd(m, n);
    }
}
