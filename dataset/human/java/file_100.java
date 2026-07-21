import java.util.*;

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
        int N = Integer.parseInt(scanner.nextLine());
        long[] a = Arrays.stream(scanner.nextLine().split(" ")).mapToLong(Long::parseLong).toArray();
        boolean even = Arrays.stream(a).filter(x -> x < 0).count() % 2 == 0;
        long total = Arrays.stream(a).map(Math::abs).sum();
        long min = Arrays.stream(a).map(Math::abs).min().orElse(0);
        System.out.println(even ? total : total - 2 * min);
    }
}
