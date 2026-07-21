import java.io.*;
import java.util.*;

@SuppressWarnings("unchecked")
public class Main {
    private static final long MOD = (int)1e9 + 7;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];

        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; ++i) {
            b[n - i - 1] = in.nextInt();
        }

        int x = -1;
        int maxI = Integer.MIN_VALUE;
        int minI = Integer.MAX_VALUE;

        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i]) {
                minI = Math.min(minI, i);
                maxI = Math.max(maxI, i);
                x = a[i];
            }
        }

        int i = 0;
        int idx = minI;
        while (i < n) {
            if (idx >= minI && idx <= maxI && a[i] != x && b[i] != x && minI <= maxI) {
                int temp = b[i];
                b[i] = x;
                b[idx++] = temp;
            }
            ++i;
        }
        
        for (i = 0; i < n; ++i) {
            if (a[i] == b[i]) {
                System.out.println("No");
                return;
            }
        }

        System.out.println("Yes");
        for (i = 0; i < n; ++i) {
            System.out.print(b[i] + " ");
        }
    }
}
