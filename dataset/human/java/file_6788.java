import java.util.*;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();

        int[] dist = new int[n];
        int a0 = sc.nextInt();
        int prev = a0;

        for (int i = 0; i < n - 1; i++) {
            int now = sc.nextInt();
            dist[i] = now - prev;
            prev = now;
        }
        dist[n - 1] = k + a0 - prev;

        System.out.println(k - IntStream.of(dist).max().orElse(0));
    }
}
