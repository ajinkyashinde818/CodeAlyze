import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    static int gcd(int a, int b) {
        if (a < b) {
            int t = a;
            a = b;
            b = t;
        }
        if (a % b == 0) {
            return b;
        }

        return gcd(a, a % b);
    }

    public static void main(String[] args) {
        Scanner std = new Scanner(System.in);
        int A = std.nextInt();
        int B = std.nextInt();
        int K = std.nextInt();

        int a = gcd(A, B);
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

        for (int i = 1; i <= a; i++) {
            if (a % i == 0) {
                pq.add(i);
            }
        }

        int value = 0;
        for (int i = 0; i < K; i++) {
            value = pq.poll();
        }

        System.out.println(value);
    }
}
