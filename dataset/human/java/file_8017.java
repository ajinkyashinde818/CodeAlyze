import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int A = scanner.nextInt();
        int B = scanner.nextInt();

        Map<Integer, Integer> factorA = new HashMap<>();
        Map<Integer, Integer> factorB = new HashMap<>();

        long answer = 1;

        int max = Math.max(A, B);
        boolean[] primes = new boolean[max + 1];
        for (int i = 2 ; i <= max ; i++) {
            primes[i] = true;
        }

        for (int i = 2 ; i * i <= max ; i++) {
            if (primes[i]) {
                int p = i + i;
                while (p <= max) {
                    primes[p] = false;
                    p += i;
                }
            }
        }

        List<Integer> plist = new ArrayList<>();
        for (int i = 2 ; i <= max ; i++) {
            if (primes[i]) plist.add(i);
        }

        for (int p : plist) {
            int countA = 0;
            while (A % p == 0) {
                A = A / p;
                countA++;
                factorA.put(p, factorA.getOrDefault(p, 0) + 1);
            }
            int countB = 0;
            while (B % p == 0) {
                B = B / p;
                countB++;
                factorB.put(p, factorB.getOrDefault(p, 0) + 1);
            }

            if (Math.max(countA, countB) != 0) {
                for (int i = 0 ; i < Math.max(countA, countB) ; i++) {
                    answer *= p;
                }
            }

        }

        System.out.println(answer);
    }
}
