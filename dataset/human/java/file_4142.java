import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.solve();
    }
    public void solve() {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = scan.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N-1];
        for (int i = 0; i < N; i++) {
            A[i] = scan.nextInt();
        }
        for (int i = 0; i < N; i++) {
            B[i] = scan.nextInt();
        }
        for (int i = 0; i < N-1; i++) {
            C[i] = scan.nextInt();
        }
        int answer = B[A[0]-1];
        for (int i = 1; i < N; i++) {
            answer += B[A[i]-1];
            if (A[i-1] + 1 == A[i]) {
                answer += C[A[i-1]-1];
            }
        }
        System.out.println(answer);
    }
}
