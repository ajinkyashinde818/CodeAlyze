import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if (n % 2 != 0) {
            System.out.println(0);
            return;
        }
        n /= 2;

        long ans = 0;
        for (long five = 5; five <= n; five *= 5) {
            ans += n / five;
            // System.out.println(ans);
        }
        System.out.println(ans);
    }
}
