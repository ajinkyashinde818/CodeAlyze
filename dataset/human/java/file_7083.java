import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int K = s.nextInt();
        int N = s.nextInt();
        int A[] = new int[N];
        int A_min[] = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = s.nextInt();
        }

        culRoot(A, A_min, K, N);
        Arrays.sort(A_min);

        System.out.println(A_min[0]);

        s.close();
    }

    public static void culRoot(int A[], int A_min[], int K, int N) {
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                A_min[i] = min(A[N - 1] - A[0], A[0] + K - A[1]);
            } else if (i == N - 1) {
                A_min[i] = min(A[N - 1] - A[0], A[N - 2] + K - A[N - 1]);
            } else {
                A_min[i] = min(K - (A[i] - A[i - 1]), K - (A[i + 1] - A[i]));
            }
        }
    }

    public static int min(int X, int Y) {
        if (X >= Y) {
            return Y;
        } else {
            return X;
        }
    }
}
