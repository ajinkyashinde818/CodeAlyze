import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long a = in.nextInt();
        long b = in.nextInt();
        long lcm = a * b / gcd(a,b);
        System.out.println(lcm);
    }
    private static long gcd(long a, long b) {
        if(a==b) {
            return a;
        }
        if(b>a) {
            // swap
            long s = a;
            a = b;
            b = s;
        }
        while(true) {
            long mod = a % b;
            if(mod==0) {
                return b;
            }
            a = b;
            b = mod;
        }
    }
}
