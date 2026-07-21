import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long tmp = n;
        long ans = 0;
        if (n < 10 || n % 2 == 1) {
            System.out.println(0);
            return;
        }
        while (n > 0) {
            long current = n / 5;
            ans += current / 2;
            n /= 5;
        }
        System.out.println(ans);
    }
}
