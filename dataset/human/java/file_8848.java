import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();

        Set<Integer> as = divisor(a);
        Set<Integer> bs = divisor(b);

        List<Integer> bothDivisor = new ArrayList<>();
        for (int i = 1; i <= Math.max(a, b); i++) {
            if (as.contains(i) && bs.contains(i)) {
                bothDivisor.add(i);
            }
        }

        // k番目。ではなく大きい方からk番目
        System.out.println(bothDivisor.get(bothDivisor.size() - k));
    }

    static Set<Integer> divisor(int n) {
        Set<Integer> ret = new HashSet<>();
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ret.add(i);
                if (i != n / i)
                    ret.add(n / i);
            }
        }
        return ret;
    }
}
