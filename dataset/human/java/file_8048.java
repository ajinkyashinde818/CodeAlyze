import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = Long.parseLong(sc.next());
        long b = Long.parseLong(sc.next());
        System.out.println((a * b) / getGcd(a, b));
    }

    private static long getGcd(long x, long y) {
        return y == 0 ? x : getGcd(y, x % y);
    }
}
