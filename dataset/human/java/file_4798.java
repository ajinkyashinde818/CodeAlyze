import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        @SuppressWarnings("resource")
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if (n % 2 == 1) {
            System.out.println(0);
            return;
        }
        if (n < 10) {
            System.out.println(0);
            return;
        }
        long ans = 0;
        for (int i = 1 ; i < 30 ; i++) {
            ans += n / (long) (2 * Math.pow(5, i));
        }

        System.out.println(ans);
    }

}
