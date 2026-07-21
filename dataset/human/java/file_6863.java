import java.util.Arrays;
import java.util.Scanner;

class C {
    public static void main(String... args) {
        final Scanner sc = new Scanner(System.in);
        final int K = sc.nextInt();
        final int N = sc.nextInt();
        final int[] A = new int[N];
        Arrays.setAll(A, i -> sc.nextInt());
        int ans = A[N - 1] - A[0];
        for (int i = 1; i < N; i++)
            ans = Math.min(ans, K - A[i] + A[i - 1]);
        System.out.println(ans);
    }
}
public class Main {
    public static void main(String... args) {
        C.main();
    }
}
