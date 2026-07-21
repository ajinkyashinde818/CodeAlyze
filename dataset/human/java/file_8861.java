import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    private void solve() {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt();

        List<Integer> candidates = new ArrayList<>();
        for (int i = 1; i <= 100; i++) {
            if (((A % i) == 0) && ((B % i) == 0)) {
                candidates.add(i);
            }
        }
        candidates.sort((a, b) -> b - a);

        System.out.println(candidates.get(K - 1));
    }

    // Main
    public static void main(String[] args) {
        new Main().solve();
    }

}
