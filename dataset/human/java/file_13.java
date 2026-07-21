import java.util.*;

/**
 * Copyright © 2018 Chris. All rights reserved.
 *
 * @author Chris
 * 2018/7/5 22:51
 */
public class Main {

    final static int MOD = 1000000007;
    static Scanner sc;

    private static int comb(int n, int m) {
        return 1;
    }

    static void getDiv(Map<Integer, Integer> map, int n) {
        int sqrt = (int) Math.sqrt(n);
        for (int i = sqrt; i >= 2; i--) {
            if (n % i == 0) {
                getDiv(map, i);
                getDiv(map, n / i);
                return;
            }
        }
        map.put(n, map.getOrDefault(n, 0) + 1);
    }

    @SuppressWarnings("unchecked")
    private static void solve() {
        int n = nextInt();
        if (n == 1) {
            System.out.println("Yes");
            System.out.println(2);
            System.out.println("1 1");
            System.out.print("1 1");
            return;
        }
        int sum = n * 2;
        int m = (int) Math.sqrt(sum + 0.5);
        if (m * (m + 1) != sum) {
            System.out.print("No");
            return;
        }
        boolean ok = true;
//        int cnt[] = new int[n + 1];
        List<Integer>[] ans = new List[m + 2];
        for (int i = 1; i <= m + 1; i++) {
            ans[i] = new ArrayList<>();
        }
        for (int i = 1; i <= m; i++) {
            ans[1].add(i);
            ans[i + 1].add(i);
//            cnt[i] = 2;
        }
        int next = m + 1;
        for (int i = 2; i <= m + 1; i++) {
            for (int j = ans[i].size() + 1; j <= m; j++) {
//                cnt[next] = 2;
                ans[i].add(next);
                ans[j + 1].add(next);
                if (++next > n) {
                    break;
                }
            }
            if (next > n) {
                break;
            }
        }
        for (int i = 1; i <= m + 1; i++) {
            if (ans[i].size() != m) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            System.out.print("No");
        } else {
            System.out.println("Yes");
            System.out.println(m + 1);
            for (int i = 1; i <= m + 1; i++) {
                System.out.print(m);
                for (int j = 0; j < m; j++) {
                    System.out.print(" " + ans[i].get(j));
                }
                if (i < m + 1) System.out.println();
            }
        }
    }

    static long gcd(long a, long b) {
        if (a < b) {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        while (b != 0) {
            long tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    public static void main(String args[]) {
        sc = new Scanner(System.in);
        solve();
    }

    private static int nextInt() {
        return sc.nextInt();
    }

    private static long nextLong() {
        return sc.nextLong();
    }

    private static String next() {
        return sc.next();
    }

    private static double nextDouble() {
        return sc.nextDouble();
    }
}
