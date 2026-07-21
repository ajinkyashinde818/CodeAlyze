import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int k = Integer.parseInt(sc.next());
        int n = Integer.parseInt(sc.next());

        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(sc.next());

        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            int y = a[(n - 1 + i) % n];
            int z = 0;
            if (x < y) {
                z = y - x;
            } else {
                z = y + (k - x);
            }

            if (ans > z) {
                ans = z;
            }
        }

        System.out.println(ans);

    }
}
