import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static final int MOD = 1_000_000_007;
    private static final String YES = "Yes";
    private static final String NO = "No";

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long N = sc.nextLong();

        System.out.println(solve(N));
    }

    private static int solve(long N) {
        int count = 0;

        List<Pair> list = primeFactorize(N);
        for (int i=0; i<list.size(); i++) {
            Pair p = list.get(i);

            for (int j=1; j<=p.second; j++) {
                count++;
                p.second -= j;
            }
        }

        return count;
    }

    /**
     * Nを素因数分解する
     * @param N
     * @return
     */
    private static List<Pair> primeFactorize(Long N) {
        List<Pair> list = new ArrayList();


        for (long p=2; p*p <= N; p++) {
            if (N%p != 0) continue;
            int num = 0;
            while (N%p == 0) {
                num++;
                N /= p;
            }

            list.add(new Pair(p, num));
        }
        if (N != 1) {
            list.add(new Pair(N, 1));
        }

        return list;
    }

    public static class Pair {
        long first;
        long second;

        public Pair(long a, long b) {
            this.first = a;
            this.second = b;
        }
    }
}
