import java.util.Scanner;

public class Main {
    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        System.out.println(lcm(A, B));
    }


    static long gcd(long a, long b) {
        long max = Math.max(a, b);
        long min = Math.min(a, b);

        long r = max % min;
        if (r == 0) {
            return min;
        } else {
            return gcd(min, r);
        }
    }

    static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
}
