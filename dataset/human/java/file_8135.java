import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = Long.parseLong(sc.next());
        long B = Long.parseLong(sc.next());

        System.out.println(LCM(A, B));
    }

    public static long GCD(long a, long b) {
        long c = a % b;
        if (c == 0) {
            return b;
        } else {
            return GCD(b, c);
        }
    }

    public static long LCM(long a, long b) {
        return (a * b) / GCD(a, b);
    }
}
