import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();

        if (n % 2 != 0) {
            System.out.println(0);
            System.exit(0);
        }

        int max = 26;
        long[] count = new long[max + 1];
        for (int i = 1; i <= max; i++) {
            count[i] = n / (pow(5, i) * 2);
//            System.out.println(i + ":" + count[i]);
        }

        long ans = 0;
        for (int i = 1; i < max; i++) {
            ans += (count[i] - count[i + 1]) * i;
        }

        System.out.println(ans);

        sc.close();
    }

    static long pow(int base, int n) {
        long ret = 1;
        for (int i = 0; i < n; i++) {
            ret *= base;
        }
        return ret;
    }
}
