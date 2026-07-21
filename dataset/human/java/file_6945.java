import java.io.*;
import java.util.*;

public class Main {

    public static void main(final String[] args) throws Exception {
        final Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];
        for(int i = 0 ; i < N ; i++){
                A[i] = sc.nextInt();
        }

        final Solver solver = new Solver();
        solver.solve(K, N, A);
    }
}

class Solver {
    public void solve(int K, int N, int[] A) {
        long min = Long.MAX_VALUE;

        for (int i = 0; i < N; i++) {

            long backward = i == N - 1?
                    A[i] - A[0] :
                    A[i] + (K - A[i + 1]);

            long forward = i == 0 ?
                    A[N - 1] - A[i] :
                    (K - A[i]) + A[i - 1];

            long shorter = Math.min(backward, forward);
            min = Math.min(min, shorter);
        }

        System.out.println(min);
    }
}
