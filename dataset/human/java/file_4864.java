import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        if (N%2 == 1) {
            System.out.println(0);
            return;
        }
        long n = N/2;
        long tmp = 5;
        int five = 0;
        while (tmp <= n) {
            five++;
            tmp *= 5;
        }

        long ans = 0;
        long ff = 5;
        for (int i = 0; i < five; i++) {
            ans += n/ff;
            ff *= 5;
        }

        System.out.println(ans);
    }
}
