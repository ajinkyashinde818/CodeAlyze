import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author silviase
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DDivGame solver = new DDivGame();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDivGame {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            long n = in.nextLong();
            ArrayList<Integer> pr = Prime.eratosthenesSieve(2000000);
            int res = 0;
            for (long prime : pr) {
                int cnt = 0;
                while (n % prime == 0) {
                    //if(cnt == 0) out.println(prime);
                    n /= prime;
                    cnt++;
                }

                //if (cnt > 0) out.println(cnt);
                int plus = cnt < 1 ? 0 :
                        cnt < 3 ? 1 :
                                cnt < 6 ? 2 :
                                        cnt < 10 ? 3 :
                                                cnt < 15 ? 4 :
                                                        cnt < 21 ? 5 :
                                                                cnt < 28 ? 6 :
                                                                        cnt < 36 ? 7 :
                                                                                cnt < 45 ? 8 :
                                                                                        cnt < 55 ? 9 : 10;
                //if(plus > 0) out.println("p:" + plus);
                res += plus;
            }
            if (n != 1) res++;
            out.println(res);
        }

    }

    static class Prime {
        public static ArrayList<Integer> eratosthenesSieve(int n) {
            // n 以下の素数を列挙する, O(N*log(log N))
            ArrayList<Integer> prime = new ArrayList<>();
            ArrayList<Integer> nums = new ArrayList<>();
            for (int i = 2; i <= n; i++) {
                nums.add(i);
            }
            while (nums.get(0) <= Math.sqrt(n)) {
                int nxtPrime = nums.get(0);
                prime.add(nxtPrime);
                nums.removeIf(x -> (x % nxtPrime == 0));
            }
            prime.addAll(nums);
            return prime;
        }

    }
}
