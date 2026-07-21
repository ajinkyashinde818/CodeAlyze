//package atcoder;

import java.util.*;

public class Main {

    private static final int MAX = 1000000;     // Wa want a solution with time O(Sqrt(N)) = O(Sqrt(10^12)) = 10^6.

    private static final int[] lp = new int[MAX + 1];
    private static final List<Integer> pr = new ArrayList<>();

    static {            // fast Eratosthenes sieve
        for (int i = 2; i <= MAX; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr.add(i);
            }
            for (int j = 0; j < pr.size() && pr.get(j) <= lp[i] && i*pr.get(j) <= MAX; ++j) {
                lp[(i * pr.get(j))] = pr.get(j);
            }
        }
    }

    public static void main (String[] args) {

        final Scanner in = new Scanner(System.in);
        long N = in.nextLong();

        final long B = (long)Math.sqrt(N) + 1;
        long count = 0;

        for (int prime = 2; prime <= Math.min(B, MAX); ++prime) {
            if (lp[prime] == prime && (N > 0) && (N % prime == 0)) {
                long z = prime;
                while ((N > 0) && (N % z == 0)) {   // try all z = prime, prime^2, prime^3, ...
                    count++;
                    N = N/z;
                    z = z*prime;
                }

                while ( (N > 0) && (N % prime == 0) ) {  // exhaust prime as a factor of N
                    N = N/prime;
                }
            }
        }

        if (N > 1) {
            count++;
        }

        System.out.println(count);
    }
}
