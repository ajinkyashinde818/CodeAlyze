import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(lcm(sc.nextInt(), sc.nextInt()));
    }

    private static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    private static long gcd(long a, long b) {
        if(a < b) return gcd(b, a);
        if(b == 0) return a;
        return gcd(b, a % b);
    }
}
