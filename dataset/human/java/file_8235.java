import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        final Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();
        long x = lcm(A, B);
        System.out.println(A*B/x);
    }

    public static long lcm(long a, long b) {
        if (a < b) {
            return lcm(b, a);
        } else if (a == b) {
            return 1;
        } else if (a%b==0) {
            return b;
        }
        return lcm(b, a%b);
    }
}
