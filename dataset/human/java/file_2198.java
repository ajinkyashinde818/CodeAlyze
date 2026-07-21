import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        final Scanner sc  = new Scanner(System.in);
        long          N   = sc.nextLong();
        int           ans = 0;
        long          q   = 2;
        int           e   = 1;
        long          div;

        if (N == 1) {
            System.out.println(0);
            return;
        }

        while (true) {
            div = (long) Math.pow(q, e);
            if (N % div == 0) {
                N /= div;
                ans++;
                e++;
                continue;
            }

            while (N % q == 0) {
                N /= q;
            }
            if (q == 2) {
                q++;
            } else {
                q += 2;
            }
            e = 1;
            
            if (q * q > N) {
                break;
            }
        }

        if (N != 1) {
            ans++;
        }

        System.out.println(ans);
    }
}
