import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = Long.parseLong(sc.next());
        if (n % 2 != 0) {
            System.out.println(0);
            return;
        }
        long ans = 0;
        n /= 2;
        while (n != 0) {
            ans += n / 5;
            n /= 5;
        }
        System.out.println(ans);
    }
}
