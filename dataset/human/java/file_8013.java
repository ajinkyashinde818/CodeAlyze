import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();

        long gcd = gcd(a, b);
        System.out.println((long) a * b / gcd);
    }

    private static long gcd(long i, long j) {
        if (j == 0) {
            // recursive divide complete
            return i;
        }
        if (i % j == 0) {
            return j;
        } else {
            return gcd(j, i % j);
        }
    }
}
