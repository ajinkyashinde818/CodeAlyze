import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if (n % 2 != 0) {
            System.out.println(0);
            return;
        }
        long ans = 0;
        long i = 10;
        while (i <= n) {
            ans += n / i;
            i *= 5;
        }
        System.out.println(ans);
    }

}
