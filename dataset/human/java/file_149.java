import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        long ans = 0;
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            queue.add(sc.nextInt());
        }
        for (int i = 0; i <= n / 2; i++) {
            if (queue.isEmpty()) {
                break;
            }
            long v1 = queue.poll();
            if (queue.isEmpty()) {
                ans += v1;
            } else {
                long v2 = queue.poll();
                long vs = v1 + v2;
                ans += Math.abs(vs);
            }
        }

        System.out.println(ans);
    }
}
