import java.util.*;

import static java.lang.System.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = ni();
        long[] A = nlarr(N);
        Arrays.sort(A);

        long BSum = 0;
        for (int i = 0; i < N; i++) {
            BSum += A[i];
        }

        for (int i = 0; i < N - 1; i +=2 ) {
            if (A[i] <= 0 && A[i + 1] <= 0) {
                BSum += 2 * Math.abs(A[i] + A[i + 1]);
            } else if (A[i] <= 0 && A[i + 1] >= 0) {
                if (Math.abs(A[i]) > A[i + 1]) {
                    BSum += 2 * Math.abs(A[i]) - 2 * A[i + 1];
                }
            }
        }

        out.println(BSum);
    }

    static int ni() {
        return sc.nextInt();
    }

    static long nl() {
        return sc.nextLong();
    }

    static String ns() {
        return sc.next();
    }

    static int[] niarr(int N) {
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }
        return a;
    }

    static long[] nlarr(int N) {
        long[] a = new long[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextLong();
        }
        return a;
    }
}
