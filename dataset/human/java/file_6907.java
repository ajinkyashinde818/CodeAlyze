import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];
        Integer[] D = new Integer[N];

        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        for (int i = 0; i < N - 1; i++) {
            D[i] = A[i + 1] - A[i];
        }

        D[N - 1] = K - A[N - 1] + A[0];

        Arrays.sort(D, Comparator.reverseOrder());

        System.out.println(K - D[0]);
    }
}
