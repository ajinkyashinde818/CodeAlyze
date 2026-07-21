import java.util.Arrays;
import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        solve();
    }

    private static void solve() {

        int n = scanner.nextInt();
        long k = scanner.nextLong();

        int[] next = new int[n + 1];
        boolean[] visited = new boolean[n + 1];

        for (int i = 1; i <= n; i++) {
            next[i] = scanner.nextInt();
        }


        int result = 1;

        int count = 0;

        while (count < k && !visited[result]) {
            count++;
            visited[result] = true;
            result = next[result];
        }

        Arrays.fill(visited, false);
        int count2 = 0;
        while (count + count2 < k && !visited[result]) {
            count2++;
            visited[result] = true;
            result = next[result];
        }

        if (count + count2 < k) {
            int diff = count - count2;
            long r = (k - diff) % count2;


            for (int i = 0; i < r; i++) {
                result = next[result];
            }
        }

        System.out.println(result);

    }
}
