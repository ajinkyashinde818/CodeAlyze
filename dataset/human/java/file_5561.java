import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main implements Runnable {

    private static int MOD = 1_000_000_007;

    public static void main(String[] args) {
        // Run with 32MB stack
        Thread thread = new Thread(null, new Main(), "", 32 * 1024 * 1024);
        thread.start();
    }

    @Override
    public void run() {
        final Scanner scanner = new Scanner(System.in);
        solve(scanner);
    }

    static void solve(Scanner scanner) {
        int N = Integer.parseInt(scanner.next());
        int K = Integer.parseInt(scanner.next());
        int S = Integer.parseInt(scanner.next());

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            if (i < K) {
                sb.append(S);
            } else {
                if (S == 1_000_000_000) {
                    sb.append(S - 1);
                } else {
                    sb.append(S + 1);
                }
            }
            sb.append(' ');
        }

        System.out.println(sb.toString().trim());
    }
}
