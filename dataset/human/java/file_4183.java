import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] A = new int[25];
        int[] B = new int[25];
        int[] C = new int[25];
        int manzokudo = 0;

        for (int i = 0; i < N; i++)
            A[i] = sc.nextInt();

        for (int i = 0; i < N; i++)
            B[i] = sc.nextInt();

        for (int i = 0; i < N - 1; i++)
            C[i] = sc.nextInt();

        for (int i = 0; i < N; i++) {
            manzokudo += B[A[i] - 1];
            if (i > 0 && A[i - 1] + 1 == A[i]) {
                manzokudo += C[A[i - 1]-1];
            }
        }

        System.out.println(manzokudo);


    }
}
