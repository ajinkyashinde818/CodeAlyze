import java.util.*;

class Main {
    final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        new Main().run();
    }

    private void run() {
        long a = sc.nextLong();
        long b = sc.nextLong();

        System.out.println(a * b / gcd(a, b));
    }

    private long gcd(long m, long n) {
        long r;
        while (n > 0) {
            r = m % n;
            m = n;
            n = r;
        }
        return m;
    }
}
