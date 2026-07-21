import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        System.out.print(lcm(a,b));     
    }
    public static long gcd (long a, long b) {return b>0?gcd(b,a%b):a;}
    public static long lcm (long a, long b) {return a*b/gcd(a,b);}
}
