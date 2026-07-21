import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        long[] a = new long[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextLong();
        }

        long sunuke = a[0];
        long araiguma = 0;
        for (int i = 1; i < N; i++) {
            araiguma += a[i];
        }

        long diffMin = Math.abs(sunuke - araiguma);
        for (int i = 1; i < N - 1; i++) {
            sunuke += a[i];
            araiguma -= a[i];
            diffMin = Math.min(diffMin, Math.abs(sunuke - araiguma));
        }

        out.println(diffMin);
    }
}
