import java.util.*;

public class Main {
    long MOD = 1000000007;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int minCount = 0;
        int absmin = Math.abs(a[0]);
        boolean zero = false;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0)
                minCount++;
            absmin = Math.min(absmin, Math.abs(a[i]));
            if (a[i] == 0)
                zero = true;
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += Math.abs(a[i]);
        }
        if (!zero && minCount % 2 != 0) {
            ans -= 2L * absmin;
        }

        System.out.println(ans);

    }
}
