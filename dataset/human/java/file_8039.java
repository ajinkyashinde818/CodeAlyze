import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextInt();
        long B = sc.nextInt();
        long res = lcm(A, B);
        System.out.println(res);
    }
    public static long gcd(long a, long b) {
        if(b==0) {
            return a;
        } else {
            long t = a%b;
            return gcd(b, t);
        }
    }

    public static long lcm(long a, long b) {
        long g = gcd(a,b);
        return a / g * b;
    }
}
