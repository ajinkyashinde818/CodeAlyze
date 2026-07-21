import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();

        int[] A = new int[N + 1];
        int[] B = new int[N + 1];
        int[] C = new int[N + 1];

        for (int i = 1 ; i <= N ; i++) {
            A[i] = scanner.nextInt();
        }

        for (int i = 1 ; i <= N ; i++) {
            B[i] = scanner.nextInt();
        }

        for (int i = 1 ; i < N ; i++) {
            C[i] = scanner.nextInt();
        }

        int score = 0;

        for (int i = 1 ; i <= N ; i++) {
            score += B[A[i]];
            if (A[i - 1] == A[i] - 1) {
                score += C[A[i - 1]];
            }
        }

        System.out.println(score);
    }
}
