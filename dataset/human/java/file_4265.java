import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N];
        for(int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
            A[i]--;
        }
        int[] B = new int[N];
        for(int i = 0; i < N; i++) {
            B[i] = scanner.nextInt();
        }
        int[] C = new int[N - 1];
        for(int i = 0; i < N - 1; i++) {
            C[i] = scanner.nextInt();
        }
        int ans = 0;
        for(int i = 0; i < N; i++) {
            if((i > 0) && (A[i] == A[i - 1] + 1)) {
                ans += C[A[i] - 1];
            }
            ans += B[i];
        }
        System.out.println(ans);
    }
}
