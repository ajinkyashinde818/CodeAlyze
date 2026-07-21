import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        int[] B = new int[N];
        for (int i = 0; i < N; i++) {
            B[i] = sc.nextInt();
        }
        int[] C = new int[N-1];
        for (int i = 0; i < N-1; i++) {
            C[i] = sc.nextInt();
        }
        sc.close();


        System.out.println(Buffet(N, 0, A, B, C));
    }
    public static int Buffet(int N, int index, int[] A, int[] B, int[] C) {
        if (index == N) {
            return 0;
        }
        int score = B[A[index]-1];
        if (index != 0 && A[index-1] + 1 == A[index]) {
            score += C[A[index-1]-1];
        }
        return score + Buffet(N, index + 1, A, B, C);
    }
}
