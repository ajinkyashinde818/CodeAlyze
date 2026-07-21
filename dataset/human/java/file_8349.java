import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        Set<Integer> primeNumberSet = primeNumberSet(Math.max(a, b));
        Map<Integer, Integer> divisorSetA = getDivisorList(a, primeNumberSet);
        Map<Integer, Integer> divisorSetB = getDivisorList(b, primeNumberSet);
        divisorSetB.keySet().forEach(k -> divisorSetA.put(k, Math.max(divisorSetB.get(k), divisorSetA.getOrDefault(k, 0))));
        List<Integer> list = divisorSetA.keySet().stream().map(k -> (int) Math.pow(k, divisorSetA.get(k))).collect(Collectors.toList());
        System.out.println(list.stream().mapToLong(m -> m).reduce(1, (m, n) -> m * n));
    }

    static Map<Integer, Integer> getDivisorList(int n, Set<Integer> primeNumberSet) {
        return primeNumberSet.stream().filter(f -> f <= n).filter(m -> n % m == 0).collect(Collectors.toMap(m -> m, m -> count(n, m)));
    }

    static Set<Integer> primeNumberSet(int n) {
        if (n < 2) return new HashSet<>();
        return IntStream.rangeClosed(2, n).filter(Main::isPrimeNumber).boxed().collect(Collectors.toSet());
    }

    static boolean isPrimeNumber(int n) {
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    static int count(int m, int n) {
        int count = 0;
        while (m % n == 0) {
            m = m / n;
            count++;
        }
        return count;
    }
}
