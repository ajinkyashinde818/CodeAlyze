import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            long A = in.nextLong();
            long B = in.nextLong();
            System.out.println(A * B / gcd(A, B));
        }
    }

    public static final long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
