import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner sc = new Scanner(System.in);

        long x = sc.nextLong();
        PriorityQueue<Long> queue = new PriorityQueue<>();
        parent : for (int i = 2; i <= Math.sqrt(x); i++) {
            for (int j = 2; j < Math.sqrt(i); j++) {
                if (i % j == 0) {
                    continue parent;
                }
            }
            if (queue.contains((long)i)) {
                continue;
            }
            if (x % i == 0) { // 最小の因数を求める
                int v = i;
                while (x % v == 0) {
                    x /= v;
                    queue.add((long)v);
                    v *= i;
                }
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1 && !queue.contains(x)) {
            boolean isOK = true;
            for (int j = 2; j < Math.sqrt(x); j++) {
                if (x % j == 0) {
                    isOK = false;
                    break;
                }
            }
            if (isOK) {
                queue.add(x);
            }
        }

        System.out.println(queue.size());
    }
}
