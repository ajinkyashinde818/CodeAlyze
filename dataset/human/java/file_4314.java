import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
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

            int sum = 0;
            for (int i = 0; i < N; i++) {
                sum += B[A[i]] + (i - 1 >= 0 && A[i] == A[i - 1] + 1 ? C[A[i - 1]] : 0);
            }

            System.out.println(sum);
        }
    }
}
