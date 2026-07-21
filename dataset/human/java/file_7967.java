import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = Long.parseLong(sc.next());
        long b = Long.parseLong(sc.next());

        System.out.println(lcm(a,b));
    }
    private static long gcd(long a, long b){return b>0?gcd(b,a%b):a;}
    private static long lcm(long a, long b){return a*b/gcd(a,b);}
}
