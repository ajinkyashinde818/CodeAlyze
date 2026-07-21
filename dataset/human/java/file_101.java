import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        long[] A = new long[N];

        for (int i=0; i<N; i++) {
            A[i] = sc.nextLong();
        }

        System.out.println(solve(N, A));
    }

    private static long solve(int N, long[] A) {
        boolean contain0 = false;
        int minusCount = 0;
        long minAbs = Long.MAX_VALUE;
        long sum = 0;

        for (int i=0; i<N; i++) {
            sum += Math.abs(A[i]);

            if (A[i] == 0) contain0 = true;
            if (A[i] < 0) minusCount++;
            minAbs = Math.min(minAbs, Math.abs(A[i]));
        }

        if (!contain0 && minusCount%2 != 0) {
            sum -= minAbs*2;
        }

        return sum;
    }
}
