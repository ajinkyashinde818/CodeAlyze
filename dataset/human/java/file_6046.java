import java.util.*;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        Arrays.setAll(a, i -> scanner.nextInt());
        Arrays.setAll(b, i -> scanner.nextInt());

        int ans = 0;
        for (int i = 1 << 28; i > 0; i >>= 1) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                a[j] &= 2 * i - 1;
                b[j] &= 2 * i - 1;
            }
            Arrays.sort(a);
            Arrays.sort(b);

            int p1 = 0, p2 = 0, p3 = 0;
            for (int j = n - 1; j >= 0; j--) {
                while (p1 < n && a[j] + b[p1] < i) p1++;
                while (p2 < n && a[j] + b[p2] < 2 * i) p2++;
                while (p3 < n && a[j] + b[p3] < 3 * i) p3++;
                count += n + p2 - p1 - p3;
                count &= 1;
            }
            if (count % 2 == 1) {
                ans |= i;
            }
        }
        System.out.println(ans);
    }
}
