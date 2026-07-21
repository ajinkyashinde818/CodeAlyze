import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        long lcm = (long)a * b / gcd(a,b);
        System.out.println(lcm);
    }

    private static int gcd(int a, int b) {
        int t;
        while (a%b != 0) {
            t = b;
            b = a%b;
            a = t;
        }
        return b;
    }
}
