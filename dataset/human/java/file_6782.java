import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            A[i] = sc.nextInt();
        }
        A[0] = A[N] - K;

        int aaa = Integer.MIN_VALUE;

        for (int i = 1; i <= N; i++) {
            aaa = Math.max(A[i] - A[i - 1], aaa);
        }

        System.out.println(K - aaa);

    }

}
