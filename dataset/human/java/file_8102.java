import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);

        final int A = sc.nextInt();
        final int B = sc.nextInt();

        System.out.println(lcm(A, B));
    }

    private static long lcm(final long a, final long b) {
        return a / gcd(a, b) * b;
    }

    private static long gcd(final long a, final long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
}
