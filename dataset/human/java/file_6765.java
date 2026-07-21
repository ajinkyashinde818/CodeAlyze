import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        int maxd = K  - A[A.length - 1] + A[0];

        for (int i = 0; i < (N - 1); i++) {
            maxd = Math.max(maxd, A[i + 1] - A[i]);
        }

        System.out.println(K-maxd);
    }
}
