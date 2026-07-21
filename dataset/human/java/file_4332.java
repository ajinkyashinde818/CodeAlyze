import java.util.Scanner;

public class Main {

    void solve() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N + 1];
        int[] B = new int[N + 1];
        int[] C = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            A[i] = sc.nextInt();
        }
        for (int i = 1; i <= N; i++) {
            B[i] = sc.nextInt();
        }
        for (int i = 1; i <= N - 1; i++) {
            C[i] = sc.nextInt();
        }

        int sum = 0;
        int prevIndex = 0;
        for (int i = 1; i <= N; i++) {
            int currentIndex = A[i];
            sum += B[currentIndex];
            if (currentIndex == (prevIndex + 1)) {
                sum += C[prevIndex];
            }
            prevIndex = currentIndex;
        }
        System.out.print(sum);
    }

    // Main
    public static void main(String[] args) {
        new Main().solve();
    }
}
