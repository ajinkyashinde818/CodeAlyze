import java.util.stream.IntStream;

public class Main {
    private static java.util.Scanner scanner = new java.util.Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt(), m = scanner.nextInt();
        boolean[] isConnectedFirst = new boolean[n], isConnectedLast = new boolean[n];
        for (int i = 0, a, b; i < m; i++) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            if (a == 1) isConnectedFirst[b] = true;
            if (a == n) isConnectedLast[b] = true;
            if (b == 1) isConnectedFirst[a] = true;
            if (b == n) isConnectedLast[a] = true;
        }
        System.out.println(IntStream.range(0, n).anyMatch(i -> isConnectedFirst[i] && isConnectedLast[i]) ? "POSSIBLE" : "IMPOSSIBLE");
    }
}
