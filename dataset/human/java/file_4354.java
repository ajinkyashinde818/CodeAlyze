import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;
import java.util.HashSet;
import java.util.Iterator;

class Main {

    static final int MOD = 1000000007;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];
        long ans = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt() - 1;
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        for (int i = 0; i < n - 1; i++) {
            c[i] = sc.nextInt();
        }
        c[n - 1] = 0;
        int prev = n - 1;
        for (int i = 0; i < n; i++) {
            ans += b[a[i]];
            if (prev == a[i] - 1)
                ans += c[prev];
            prev = a[i];
        }
        System.out.println(ans);
    }
}
