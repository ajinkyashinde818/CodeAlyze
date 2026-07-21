import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();

        long max = Math.max(a, b);
        List<Long> list = new ArrayList<>();
        for (long i = max; i >= 2; i--) {
            if (a % i == 0 && b % i == 0) {
                boolean skip = false;
                for (long j : list) {
                    if (j % i == 0) {
                        skip = true;
                    }
                }
                if (!skip) {
                    list.add(i);
                }
            }
        }

        long ans = a * b;
        for (long i : list) {
            ans /= i;
        }
        System.out.println(ans);

        sc.close();
    }

}
