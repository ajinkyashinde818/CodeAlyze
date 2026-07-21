import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int K = sc.nextInt();
            int N = sc.nextInt();
            int[] A = new int[N];
            for (int i = 0; i < N; i++) {
                A[i] = sc.nextInt();
            }

            int max = (K + A[0]) - A[N - 1];
            for (int i = 1; i < N; i++) {
                max = Math.max(max, A[i] - A[i - 1]);
            }

            System.out.println(K - max);
        }
    }
}
