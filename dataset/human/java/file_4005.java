import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        final int N = scan.nextInt();
        int A[] = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scan.nextInt() - 1;
        }
        int B[] = new int[N];
        for (int i = 0; i < N; i++) {
            B[i] = scan.nextInt();
        }
        int C[] = new int[N];
        for (int i = 0; i < N - 1; i++) {
            C[i] = scan.nextInt();
        }
        scan.close();

        int score = 0;
        for (int i = 0; i < N; i++) {
            score += B[A[i]];
            if (i > 0) {
                if (A[i] - A[i - 1] == 1) {
                    score += C[A[i - 1]];
                }
            }
        }
        System.out.println(score);
    }    
}
