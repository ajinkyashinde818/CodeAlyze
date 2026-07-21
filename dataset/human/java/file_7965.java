import java.math.BigInteger;
import java.util.*;

class Main {
    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);
        final BigInteger A = new BigInteger(sc.next());
        final BigInteger B = new BigInteger(sc.next());
        sc.close();

        BigInteger C = A.gcd(B);
        long ans = A.multiply(B).divide(C).longValue();
        System.out.println(ans);
    }
}
