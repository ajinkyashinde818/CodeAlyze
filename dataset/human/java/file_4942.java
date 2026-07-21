import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // ABC148E - Double Factorial

        Scanner sc = new Scanner(System.in);

        long n = sc.nextLong();

        if (n % 2 == 1) {
            System.out.println(0);
            return;
        }

        long ans = 0;

        for (long i = 10; i <= n; i *= 5) {
            ans += n / i;
        }

        System.out.println(ans);
    }

}
