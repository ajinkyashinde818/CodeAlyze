import java.util.*;

class Main {
    public static void main(String[] args) {
        new Solver().run();
    }
}

class Solver {

    private List<long[]> prime_factorize(long N) {
        List<long[]> res = new ArrayList<long[]>();
        for (long a = 2; a * a <= N; a++) {
            if (N % a != 0) continue;
            long ex = 0;

            while (N % a == 0) {
                ++ex;
                N /= a;
            }   

            res.add(new long[]{a, ex});
        }   

        if (N != 1) res.add(new long[]{N, 1});
        return res;
    } 

    public void run() {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        List<long[]> list = prime_factorize(N);

        long ans = 0;
        for (long[] p : list) {
            long num = p[0];
            long cnt = p[1];
            //System.out.println(String.format("%d %d", num, cnt));

            long i = 1;
            while (cnt - i >= 0) {
                ans++;
                //System.out.println(String.format("\t%d %d", cnt, i));
                cnt -= i;
                i++;
            }
        }

        System.out.println(ans);
        return;
    }

}
