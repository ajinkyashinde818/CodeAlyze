import java.math.BigInteger;
import java.util.*;

public class Main {

    private static Scanner sc = new Scanner(System.in);
    private static final BigInteger MOD = BigInteger.valueOf(1_000_000_007);

    public static void main(String[] args) {

        int n = sc.nextInt();
        int m = sc.nextInt();

        List<Integer> a = new ArrayList<>();

        for (int i=0; i < m; i++) {
            a.add(sc.nextInt());
        }

        a.sort((Comparator.comparingInt(o -> o)));

        BigInteger ans = BigInteger.ONE;
        if (check(a)) {
            for (int i=0; i < m-1; i++) {
                // System.out.printf("For from %s to %s, multiplying %s\n", a.get(i), a.get(i+1), permutations(
                //        a.get(i + 1) - a.get(i) - 2
                //));
                ans = ans.multiply(permutations(
                        a.get(i + 1) - a.get(i) - 2
                )).mod(MOD);
            }

            if (a.size() > 0) {
                // System.out.printf("For from %s to %s, multiplying %s\n", a.get(m-1), n, permutations(
                //        n - a.get(m-1) - 1
                //));

                ans = ans.multiply(permutations(
                        n - a.get(m-1) - 1
                )).mod(MOD);

                // System.out.printf("For from %s to %s, multiplying %s\n", 0, a.get(0), permutations(
                //        a.get(0) - 1
                //));

                ans = ans.multiply(permutations(
                        a.get(0) - 1
                )).mod(MOD);
            } else {
                ans = ans.multiply(permutations(
                        n
                ));
            }

            System.out.println(ans.mod(MOD));

        } else {
            System.out.println(0);
        }

    }

    private static boolean check(List<Integer> a) {
        for (int i=0; i < a.size()-1; i++) {
            if (a.get(i) + 1 == a.get(i+1))
                return false;
        }
        return true;
    }

    private static HashMap<Integer, BigInteger> permutationsDP = new HashMap<>();

    private static BigInteger permutations(int n) {
        if (permutationsDP.containsKey(n))
            return permutationsDP.get(n);

        if (n < 2)
            return BigInteger.ONE;

        BigInteger ans = permutations(n-1).add(permutations(n-2));
        permutationsDP.put(n, ans);
        return ans;

        /*
        BigInteger ans = BigInteger.ZERO;
        if (n % 2 == 0) {
            for (int i=0; i <= n/2; i++) {
                ans = ans.add(
                        factorial(n-i).divide(factorial(i)).divide(factorial(n-2*i))
                ).mod(MOD);
            }
        } else {
            for (int i=0; i <= (n-1)/2; i++) {
                ans = ans.add(
                        factorial(n-i).divide(factorial(i)).divide(factorial(n-2*i))
                ).mod(MOD);
            }
        }

        permutationsDP.put(n, ans);
        return ans.mod(MOD);
         */
    }

    /*
    private static HashMap<Integer, BigInteger> factDP = new HashMap<>();

    private static BigInteger factorial(int n) {
        if (n < 2)
            return BigInteger.ONE;
        else {
            if (factDP.containsKey(n))
                return factDP.get(n);
            BigInteger ans = factorial(n - 1).multiply(BigInteger.valueOf(n));
            factDP.put(n, ans);
            return ans;
        }
    }
     */

}
