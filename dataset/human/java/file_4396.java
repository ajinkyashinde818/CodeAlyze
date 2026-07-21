import java.util.Scanner;

/**
 * Buffet
 */
public class Main {

    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            int N = sc.nextInt();
            int[] A = new int[N];
            int[] B = new int[N];
            int[] C = new int[N - 1];

            for (int i = 0; i < N; i++) {
                A[i] = sc.nextInt() - 1;
            }
            for (int i = 0; i < N; i++) {
                B[i] = sc.nextInt();
            }
            for (int i = 0; i < N - 1; i++) {
                C[i] = sc.nextInt();
            }

            int S = B[A[0]];
            for (int i = 1; i < N; i++) {
                S += B[A[i]];
                if (A[i] == A[i - 1] + 1) {
                    S += C[A[i - 1]];
                }
            }

            System.out.println(S);
        }
    }
}
