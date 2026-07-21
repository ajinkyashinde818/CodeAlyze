import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
        int m = Math.max(a, b);
        List<Integer> candidates = new ArrayList<>();
        for (int i = 1; i <= m; ++i) {
            int a_out = a % i;
            int b_out = b % i;
            if (a_out == 0 && b_out == 0) candidates.add(i);
        }
        System.out.println(candidates.get(candidates.size() - c));
    }
}
