import java.util.*;

public class Main {
    static long mod = 1000000007;

    public static long gcd(long a, long b) {
        if (a == 0) {
            return b;
        } else if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] lis = new long[n];
        int neg = 0;
        int zero = 0;
        for (int i = 0; i < n; ++i) {
            long l = sc.nextLong();
            if (l < 0) {
                neg++;
            } else if (l == 0) {
                zero++;
            }
            lis[i] = l;
        }

        long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += Math.abs(lis[i]);
        }
        if (zero > 0 || (neg % 2) == 0) {

        } else {
            long min = Math.abs(lis[0]);
            for (int i = 0; i < n; ++i) {
                min = Math.min(min, Math.abs(lis[i]));
            }
            sum -= Math.abs(min) * 2;
        }
        
        System.out.println(sum);
    }
}
